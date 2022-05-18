#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Windows/Window.h"
#include "GRAVRuntime/Rendering/GraphicsContext.h"

#include <GLFW/glfw3.h>
#include <string>

namespace GRAVRuntime::Rendering
{
	class GRAVRuntimeAPI windowsWindow : public window
	{
	public:
		windowsWindow(const windowProperties& properties);
		virtual ~windowsWindow();

		void onUpdate() override;

		// Window attributes
		GRAVLib::uint32 getWidth() const override;
		GRAVLib::uint32 getHeight() const override;

		void setEventCallback(const eventCallbackFunction& callback) override;
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline void* getNativeWindow() const;
	private:
		struct windowData
		{
			std::string m_Title;
			GRAVLib::uint32 m_Width, m_Height;
			bool m_VSync;

			eventCallbackFunction m_EventCallback;
		};

		GLFWwindow* m_Window;
		windowData m_Data;
	};

	inline GRAVLib::uint32 windowsWindow::getWidth() const { return m_Data.m_Width; }
	inline GRAVLib::uint32 windowsWindow::getHeight() const { return m_Data.m_Height; }
	inline void* windowsWindow::getNativeWindow() const { return m_Window; }

	inline void windowsWindow::setEventCallback(const eventCallbackFunction& callback) { m_Data.m_EventCallback = callback; }

}