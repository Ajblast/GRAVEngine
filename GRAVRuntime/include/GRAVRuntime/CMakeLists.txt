target_sources(${TargetName} 
	PUBLIC
		Application.h
		GRAVRuntimeCore.h
		LibExportImport.h
)

add_subdirectory(IO)
add_subdirectory(Layers)
add_subdirectory(Platform)
add_subdirectory(Primitives)
add_subdirectory(Rendering)