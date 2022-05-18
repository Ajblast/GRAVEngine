#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"

namespace GRAVRuntime::Rendering::Shaders
{
	enum class shaderDataType
	{
		NONE = 0, FLOAT, FLOAT2, FLOAT3, FLOAT4, MAT3, MAT4, INT, INT2, INT3, INT4, BOOL
	};

	static GRAVLib::uint32 shaderDataTypeSize(shaderDataType type)
	{
		switch (type)
		{
		case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT:	return 4;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT2:	return 4 * 2;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT3:	return 4 * 3;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::FLOAT4:	return 4 * 4;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::MAT3:		return 4 * 3 * 3;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::MAT4:		return 4 * 4 * 4;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::INT:		return 4;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::INT2:		return 4 * 2;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::INT3:		return 4 * 3;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::INT4:		return 4 * 4;
		case GRAVRuntime::Rendering::Shaders::shaderDataType::BOOL:		return 1;
		}

		// Unknown Shader Data Type
		GRAV_ASSERT_TRUE(false);
		return 0;
	}
}