#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Buffers/VertexBuffer.h"
#include "GRAVRuntime/Rendering/Buffers/IndexBuffer.h"

namespace GRAVRuntime::Rendering::Buffers
{
	// Stores vertex attribute configutations and which vertex buffers to use
	// Has a vertex buffer (VBO) and an index buffer (EBO)
	class GRAVRuntimeAPI vertexArray
	{
	public:
		virtual ~vertexArray();

		// Bind this vertex array
		virtual void bind() const = 0;
		// Unbind this vertex array
		virtual void unbind() const = 0;

		// Add a vertex buffer
		virtual void addVertexBuffer(const GRAVLib::ref<vertexBuffer>&vertexBuffer) = 0;
		// Set the index buffer
		virtual void setIndexBuffer(const GRAVLib::ref<indexBuffer>&indexBuffer) = 0;

		// Get a list of the vertex buffers
		virtual const std::vector<GRAVLib::ref<vertexBuffer>>& getVertexBuffers() const = 0;
		// Get the index buffer
		virtual const GRAVLib::ref<indexBuffer>& getIndexBuffer() const = 0;
	};
}