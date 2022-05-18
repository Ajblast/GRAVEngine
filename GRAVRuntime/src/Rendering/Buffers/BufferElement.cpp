#include "GRAVRuntime/Rendering/Buffers/BufferElement.h"

GRAVRuntime::Rendering::Buffers::bufferElement::bufferElement(Shaders::shaderDataType type, const std::string& name, bool normalized) :
	m_Name(name), m_Type(type), m_Size(Shaders::shaderDataTypeSize(type)), m_Offset(0), m_Normalized(normalized)
{}

GRAVLib::uint32 GRAVRuntime::Rendering::Buffers::bufferElement::getComponentCount() const
{
	switch (m_Type)
	{
	case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT:	return 1;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT2:	return 2;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT3:	return 3;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT4:	return 4;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::MAT3:	return 3; // 3* float3
	case GRAVRuntime::Rendering::Shaders::shaderDataType::MAT4:	return 4; // 4* float4
	case GRAVRuntime::Rendering::Shaders::shaderDataType::INT:	return 1;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::INT2:	return 2;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::INT3:	return 3;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::INT4:	return 4;
	case GRAVRuntime::Rendering::Shaders::shaderDataType::BOOL:	return 1;
	}

	// Unknown shader data type
	GRAV_ASSERT_TRUE(false);
	return 0;
}