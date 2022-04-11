cmake_minimum_required(VERSION 3.21)

option(GRAVEngine_BuildTests "BuildXTests" ON)

#Enable Tests
if(GRAVEngine_BuildTests)
	enable_testing()
endif()

#Set default build types
if(NOT DEFINED BuildTypes)
	set(BuildTypes
		RELEASE
		RELWITHDEBINFO
		MINSIZEREL
		DEBUG
	)
endif()

set(ProjectLanguage CXX)
project(GRAVEngine VERSION 1.0 LANGUAGES ${ProjectLanguage})

#Set C++ languages
if (${ProjectLanguage} STREQUAL CXX)
	set(CMAKE_C_STANDARD 17)
	set(CMAKE_C_STANDARD_REQUIRED True)
	set(CMAKE_CXX_STANDARD 23)
	set(CMAKE_CXX_STANDARD_REQUIRED True)
endif()

#Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

#Add vendor items
add_subdirectory(vendor/GRAVLib)

#Include Runtime Environment
add_subdirectory(GRAVRuntime)
add_subdirectory(GRAVEditor)
