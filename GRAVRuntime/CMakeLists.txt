cmake_minimum_required(VERSION 3.21)

makelib(GRAVRuntime ${PROJECT_SOURCE_DIR}/GRAVRuntime SHARED True pch.h ${GRAVEngine_BuildTests} GRAVLib)