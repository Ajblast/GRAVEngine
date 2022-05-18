#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/APIs/RendererAPI.h"
#include <GLFW/glfw3.h>

#define GRAVRuntime_GLFW_OPENGL_PROFILE GLFW_OPENGL_CORE_PROFILE


namespace GRAVRuntime::Rendering::APIs
{
	class GRAVRuntimeAPI openglAPI : public rendererAPI
	{
	public:
		openglAPI();
		virtual ~openglAPI();
	};
}