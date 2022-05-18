#include "GRAVRuntime/Platform/Windows/WindowsWindow.h"
#include "GRAVRuntime/Layers/Events/ApplicationEvents.h"
#include "GRAVRuntime/Layers/Events/MouseEvents.h"
#include "GRAVRuntime/Layers/Events/KeyEvents.h"
#include "GRAVRuntime/Rendering/APIs/RendererAPI.h"
#include "GRAVRuntime/Rendering/APIs/OpenGL/OpenglContext.h"

#include "GRAVLib/Debug/Logging/Logging.h"
#include "GRAVLib/Debug/Instrumentation/Instrumentor.h"

GRAVRuntime::Rendering::windowsWindow::windowsWindow(const windowProperties& properties)
{
	GRAVLib_PROFILE_FUNCTION();

	m_Data.m_Title = properties.m_Title;
	m_Data.m_Width = properties.m_Width;
	m_Data.m_Height = properties.m_Height;

	GRAVLib_LOG_LINE_INFO("Creating window \"{}\" ({}, {})", properties.m_Title, properties.m_Width, properties.m_Height);

	// Set whether the window is visible
	if (properties.m_Visible)
		glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
	else
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	{
		GRAVLib_PROFILE_SCOPE("glfwCreateWindow");

		// Create the window
		m_Window = glfwCreateWindow((int)properties.m_Width, (int)properties.m_Height, m_Data.m_Title.c_str(), nullptr, nullptr);
		if (m_Window == nullptr)
		{
			GRAVLib_LOG_LINE_ERROR("Error in creating window ({})", m_Data.m_Title);
			return;
		}
	}

	// Create the context of the window
	m_Context = Rendering::APIs::rendererAPI::getInstancePtr()->createContext(m_Window);
	m_Context->startup();

	bindGraphicsContext();

	// Set data associated with this window
	glfwSetWindowUserPointer(m_Window, &m_Data);
	setVSync(true);


	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, GRAVLib::int32 width, GRAVLib::int32 height)
		{
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
			data.m_Width = width;
			data.m_Height = height;

			Layers::Events::windowResizeEvent event(width, height);
			data.m_EventCallback(event);
		});
	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

			Layers::Events::windowCloseEvent event;
			data.m_EventCallback(event);
		});
	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, GRAVLib::int32 key, GRAVLib::int32 scancode, GRAVLib::int32 action, GRAVLib::int32 mods)
		{
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				Layers::Events::keyPressedEvent event((IO::keyCode)key, 0);
				data.m_EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				Layers::Events::keyReleasedEvent event((IO::keyCode)key);
				data.m_EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				Layers::Events::keyPressedEvent event((IO::keyCode)key, 1);
				data.m_EventCallback(event);
				break;
			}
			}
		});
	glfwSetCharCallback(m_Window, [](GLFWwindow* window, GRAVLib::uint32 keycode)
		{
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

			Layers::Events::keyTypedEvent event((IO::keyCode)keycode);
			data.m_EventCallback(event);
		});
	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, GRAVLib::int32 button, GRAVLib::int32 action, GRAVLib::int32 mods)
		{
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				Layers::Events::mouseButtonPressedEvent event((IO::mouseCode)button);
				data.m_EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				Layers::Events::mouseButtonReleasedEvent event((IO::mouseCode)button);
				data.m_EventCallback(event);
				break;
			}
			}
		});
	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

			Layers::Events::mouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.m_EventCallback(event);
		});
	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

			Layers::Events::mouseMovedEvent event((float)xPos, (float)yPos);
			data.m_EventCallback(event);
		});
}
GRAVRuntime::Rendering::windowsWindow::~windowsWindow()
{
	GRAVLib_PROFILE_FUNCTION();

	bindGraphicsContext();

	// Destroy the window decrement the count
	glfwDestroyWindow(m_Window);
}

void GRAVRuntime::Rendering::windowsWindow::onUpdate()
{
	GRAVLib_PROFILE_FUNCTION();

	// Swap the render buffers
	m_Context->swapBuffers();
}

void GRAVRuntime::Rendering::windowsWindow::setVSync(bool enabled)
{
	GRAVLib_PROFILE_FUNCTION();

	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_Data.m_VSync = enabled;
}
bool GRAVRuntime::Rendering::windowsWindow::isVSync() const
{
	return m_Data.m_VSync;
}