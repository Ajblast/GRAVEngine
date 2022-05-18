target_sources(${TargetName} 
	PRIVATE
		GraphicsContext.cpp
)

add_subdirectory(APIs)
add_subdirectory(Buffers)
add_subdirectory(Renderer)
add_subdirectory(Shaders)
add_subdirectory(Textures)
add_subdirectory(Windows)