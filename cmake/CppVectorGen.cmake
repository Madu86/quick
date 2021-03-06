# Utility script for converting data in a CMake list to C++ source code
# must be included after CompilationOptions because it checks for a C++11 header
# works without c++11 initalizer lists

#VECTORTYPE example: "std::string"
#VECTORNAME example: "librarynames"

# below line generates a false positive with AppleClang 8.1
#list_contains(SUPPORTS_INITIALIZER_LISTS cxx_generalized_initializers ${CMAKE_CXX_COMPILE_FEATURES})
# ...so we'll just be paranoid instead
set(SUPPORTS_INITIALIZER_LISTS FALSE)

macro(format_list_as_vector OUTPUT_VAR QUOTE LIST VECTORNAME VECTORTYPE)
	
	
	list(LENGTH ${LIST} VECTOR_LENGTH)
	
	if(${VECTOR_LENGTH} EQUAL 0)
		
		# generate an empty vector
		set(${OUTPUT_VAR} "${${OUTPUT_VAR}} 
std::vector<${VECTORTYPE}> ${VECTORNAME};
")
	
	else()
	
		
		if(SUPPORTS_INITIALIZER_LISTS)
			set(${OUTPUT_VAR} "${${OUTPUT_VAR}}
std::vector<${VECTORTYPE}> ${VECTORNAME}({")
		else()
			#because we don't have initializer list support, we have to do this the hard way
			# see http://stackoverflow.com/questions/2236197/what-is-the-easiest-way-to-initialize-a-stdvector-with-hardcoded-elements
			set(ARRAYNAME "__cmake_${VECTORNAME}_initializer_array")
			set(${OUTPUT_VAR} "${${OUTPUT_VAR}}
const ${VECTORTYPE} ${ARRAYNAME}[] = {")
		endif()
			
		
		set(FIRSTLOOP TRUE)
		foreach(ELEMENT ${${LIST}})
		
			# append a comma to the previous element if necessary
			if(NOT FIRSTLOOP)
				set(${OUTPUT_VAR} "${${OUTPUT_VAR}}, ")	
			endif()
			
			set(FIRSTLOOP FALSE)
			
			if(${QUOTE})
				set(${OUTPUT_VAR} "${${OUTPUT_VAR}}
	\"${ELEMENT}\"")
			else()
				set(${OUTPUT_VAR} "${${OUTPUT_VAR}}
	${ELEMENT}")
			endif()
		endforeach()
		
		if(SUPPORTS_INITIALIZER_LISTS)
			set(${OUTPUT_VAR} "${${OUTPUT_VAR}}
});")
		else()
			set(${OUTPUT_VAR} "${${OUTPUT_VAR}}
};
std::vector<${VECTORTYPE}> ${VECTORNAME}(${ARRAYNAME}, ${ARRAYNAME} + sizeof(${ARRAYNAME}) / sizeof(${ARRAYNAME}[0]));
")
		endif()
	endif()	
endmacro(format_list_as_vector)

# Function for linking data from CMake directly into a program
# It initializes C++ vectors with the given names to contain the data in the provided CMake lists.
# Quotes the list data if the QUOTE argument is passed
# If you need to include files to get the types used as vector template parameters, pass them as INCLUDE arguments
# Generator expressions are supported but multi-configuration generators are not.
# Usage: create_list_source_file(
#	TARGETNAME <target_name>
#	OUTPUTFILEVAR <variable to be set to output file path> 
#	[QUOTE] 
#	[INCLUDE <name of header to include>]... 
#	<vector 1 name> <vector 1 generic type> <variable containing vector 1 elements> [<vector 2 name> <vector 2 generic type> <variable containing vector 2 elements>]...)
function(create_list_source_file)

	cmake_parse_arguments(VECTORGEN "QUOTE" "TARGETNAME;OUTPUTFILEVAR;INCLUDE" "" ${ARGN})
	
	if("${VECTORGEN_TARGETNAME}" STREQUAL "" OR "${VECTORGEN_OUTPUTFILEVAR}" STREQUAL "")
		message(FATAL_ERROR "Missing arguments!")
	endif()
	
	# created from the content for each config using file(GENERATE)
	set(FINAL_VECTOR_FILE_GENEX "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/CmakeVectorData-${VECTORGEN_TARGETNAME}-$<CONFIG>.cpp")
	
	# there seems to be CMake bug (as of v3.7) where generator expressions in add_executable() are not evaluated
	# so we can't return a genex in VECTORGEN_OUTPUTFILEVAR
	set(FINAL_VECTOR_FILE_NO_GENEX "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/CmakeVectorData-${VECTORGEN_TARGETNAME}-${CMAKE_BUILD_TYPE}.cpp")
	
	set(${VECTORGEN_OUTPUTFILEVAR} ${FINAL_VECTOR_FILE_NO_GENEX} PARENT_SCOPE)
		
	set(VECTOR_FILE_CONTENT "// AUTOGENERATED!  DO NOT EDIT, YOUR CHANGES WILL BE ERASED! 
#include <vector>")

	foreach(REQUIRED_HEADER ${VECTORGEN_INCLUDE})
		set(VECTOR_FILE_CONTENT "${VECTOR_FILE_CONTENT}
#include <${REQUIRED_HEADER}>")
	endforeach()
	
	if(SUPPORTS_INITIALIZER_LISTS)
		set(VECTOR_FILE_CONTENT "${VECTOR_FILE_CONTENT}
#include <initializer_list>")
	endif()
	
	set(LOOP_COUNT 0) #0 indexed
		
	# go through the groups of three arguments and collect the data we need.
	foreach(ARG ${VECTORGEN_UNPARSED_ARGUMENTS})
		
		math(EXPR LOOP_PHASE "${LOOP_COUNT} % 3")
	
		if(${LOOP_PHASE} EQUAL 0)
			#1st argument: name of the vector
			set(VECTOR_NAME ${ARG})
		elseif(${LOOP_PHASE} EQUAL 1)
			#2nd argument: generic type of vector
			set(GENERIC_TYPE ${ARG})
		else()				
			format_list_as_vector(VECTOR_FILE_CONTENT ${VECTORGEN_QUOTE} ${ARG} ${VECTOR_NAME} ${GENERIC_TYPE})				
		endif()
		
		math(EXPR LOOP_COUNT "${LOOP_COUNT} + 1")
	endforeach()
	
	# create a version for each build configuration
	file(GENERATE OUTPUT ${FINAL_VECTOR_FILE_GENEX} CONTENT "${VECTOR_FILE_CONTENT}")
	
endfunction(create_list_source_file)