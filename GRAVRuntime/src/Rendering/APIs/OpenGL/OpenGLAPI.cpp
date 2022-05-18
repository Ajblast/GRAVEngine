#include "GRAVRuntime/Rendering/APIs/OpenGL/OpenGLAPI.h"
#include <GLFW/glfw3.h>

GRAVRuntime::Rendering::APIs::openglAPI::openglAPI()
{
	#ifndef NDEBUG
	glfwWindowHint(GLFW_OPENGL_PROFILE, GRAVRuntime_GLFW_OPENGL_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	#endif
}

GRAVRuntime::Rendering::APIs::openglAPI::~openglAPI()
{

}