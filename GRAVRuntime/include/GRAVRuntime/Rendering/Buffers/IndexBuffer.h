#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"

namespace GRAVRuntime::Rendering::Buffers
{
	class GRAVRuntimeAPI indexBuffer
	{
	public:
		virtual ~indexBuffer();

		// Bind this index buffer
		virtual void bind() const = 0;
		// Unbind this index buffer. Don't unbind before unbinding vertex array
		virtual void unbind() const = 0;

		// Get the number of indices
		virtual GRAVLib::uint32 getCount() const = 0;
	};
}