target_sources(${TargetName} 
	PRIVATE
		Application.cpp
)

add_subdirectory(Layers)
add_subdirectory(Platform)
add_subdirectory(Rendering)