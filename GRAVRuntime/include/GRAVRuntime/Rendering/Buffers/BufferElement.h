#pragma once
#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Shaders/ShaderDataTypes.h"

#include <string>

namespace GRAVRuntime::Rendering::Buffers
{
	// An element is a buffer Layout
	struct GRAVRuntimeAPI bufferElement
	{
		std::string m_Name;				// Name of the element
		Shaders::shaderDataType m_Type;	// Elment type
		GRAVLib::uint32 m_Size;			// Element size
		size_t m_Offset;				// Offset into buffer layout
		bool m_Normalized;				// Is the element normalized

		bufferElement() = default;
		bufferElement(Shaders::shaderDataType type, const std::string& name, bool normalized = false);

		// Get the number of items this element is
		GRAVLib::uint32 getComponentCount() const;
	};
}