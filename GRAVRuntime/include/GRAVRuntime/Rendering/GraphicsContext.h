#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"

namespace GRAVRuntime::Rendering
{
	// A graphical context
	class GRAVRuntimeAPI graphicsContext
	{
	public:
		virtual ~graphicsContext();

		// Startup a context.
		virtual void startup() = 0;
		// Swap the current buffers
		virtual void swapBuffers() = 0;

		// Bind this graphical context
		virtual void bind() = 0;
		// Unbind this graphical context
		virtual void unbind() = 0;
	};

}