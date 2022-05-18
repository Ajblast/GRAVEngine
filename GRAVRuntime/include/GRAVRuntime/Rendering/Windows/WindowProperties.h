#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include <string>

namespace GRAVRuntime::Rendering
{
	// Properties for window creation
	struct GRAVRuntimeAPI windowProperties
	{
	public:
		windowProperties(const std::string& title = "GRAVEngine", GRAVLib::uint32 width = 1600, GRAVLib::uint32 height = 900, bool visible = true) :
			m_Title(title), m_Width(width), m_Height(height), m_Visible(visible)
		{}

	public:
		std::string m_Title;
		GRAVLib::uint32 m_Width;
		GRAVLib::uint32 m_Height;
		bool m_Visible;
	};

}