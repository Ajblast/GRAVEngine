#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Windows/WindowProperties.h"
#include "GRAVRuntime/Rendering/GraphicsContext.h"
#include "GRAVRuntime/Layers/Events/Event.h"

#include <functional>

namespace GRAVRuntime::Rendering
{
	// Interface representing a desktop system based window
	class GRAVRuntimeAPI window
	{
	public:
		using eventCallbackFunction = std::function<void(GRAVRuntime::Layers::Events::event&)>;

	public:
		virtual ~window();

		virtual void onUpdate() = 0;

		virtual GRAVLib::uint32 getWidth() const = 0;
		virtual GRAVLib::uint32 getHeight() const = 0;

		// Window Attributes
		virtual void setEventCallback(const eventCallbackFunction& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		// Get the native representation of this window
		virtual void* getNativeWindow() const = 0;

		// Bind this window's graphical context
		void bindGraphicsContext();
		// Unbind this window's graphical context
		void unbindGraphicsContext();

		// Create a window. This must be ran on the main thread!
		static GRAVLib::scope<window> create(const windowProperties& properties = windowProperties());

	protected:
		GRAVLib::scope<graphicsContext> m_Context;	// Current Window Context
	};
}