#include "GRAVRuntime/Rendering/APIs/RendererAPI.h"
#include "GRAVLib/Debug/Logging/Logging.h"

#include <GLFW/glfw3.h>

GRAVLib_SINGLETON_SET_INSTANCE(GRAVRuntime::Rendering::APIs::rendererAPI);

static void glfwErrorCallback(int error, const char* description)
{
	GRAVLib_LOG_LINE_ERROR("GLFW Error ({}: {})", error, description);
}

GRAVRuntime::Rendering::APIs::rendererAPI::rendererAPI()
{
	int success = glfwInit();
	GRAV_ASSERT_TRUE(success);

	// Set the callback function for when glfw has an error
	glfwSetErrorCallback(glfwErrorCallback);

	GRAVLib_LOG_LINE_INFO("{}: GLFW Version {}", GRAVLib_FUNC_SIG, glfwGetVersionString());

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GRAVRuntime_GLFW_CONTEXT_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GRAVRuntime_GLFW_CONTEXT_VERSION_MINOR);
}

GRAVRuntime::Rendering::APIs::rendererAPI::~rendererAPI()
{
	glfwTerminate();
}