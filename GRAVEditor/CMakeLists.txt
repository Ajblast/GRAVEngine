cmake_minimum_required(VERSION 3.21)

makeexe(GRAVEditor ${PROJECT_SOURCE_DIR}/GRAVEditor True pch.h "GRAVLib GRAVRuntime")

target_include_directories(${ExeName} PUBLIC ${PROJECT_SOURCE_DIR}/GRAVRuntime/include)
target_include_directories(${ExeName} PUBLIC ${PROJECT_SOURCE_DIR}/vendor/GRAVLib/include)
