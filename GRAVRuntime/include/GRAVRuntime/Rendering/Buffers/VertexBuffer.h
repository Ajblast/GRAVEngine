#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Buffers/BufferLayout.h"

namespace GRAVRuntime::Rendering::Buffers
{
	class GRAVRuntimeAPI vertexBuffer
	{
	public:
		virtual ~vertexBuffer();

		// Bind this vertex buffer
		virtual void bind() const = 0;
		// Unbind this vertex buffer
		virtual void unbind() const = 0;

		// Set the data of this vertex buffer
		virtual void setData(const void* data, GRAVLib::uint32 size) = 0;

		// Get the buffer's layout
		virtual const bufferLayout& getLayout() const = 0;
		// Set the buffer's layout
		virtual void setLayout(const bufferLayout & layout) = 0;
	};
}