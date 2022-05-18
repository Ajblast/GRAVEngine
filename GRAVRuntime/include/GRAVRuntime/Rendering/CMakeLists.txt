target_sources(${TargetName} 
	PUBLIC
		GraphicsContext.h
)

add_subdirectory(APIs)
add_subdirectory(Buffers)
add_subdirectory(Cameras)
add_subdirectory(Renderer)
add_subdirectory(Shaders)
add_subdirectory(Textures)
add_subdirectory(Windows)