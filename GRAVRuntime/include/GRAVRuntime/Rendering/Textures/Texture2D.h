#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Textures/Texture.h"
#include <string>

namespace GRAVRuntime::Rendering::Textures
{
	class GRAVRuntimeAPI texture2D : public texture
	{
	public:
		texture2D(GRAVLib::uint32 width, GRAVLib::uint32 height);
		texture2D(const std::string& path);
		virtual ~texture2D();

		virtual GRAVLib::uint32 getWidth() const override;
		virtual GRAVLib::uint32 getHeight() const override;
		virtual GRAVLib::uint32 getRendererID() const override;
	protected:
		std::string m_Path;
		GRAVLib::uint32 m_Width, m_Height;
		GRAVLib::uint32 m_RendererID;
	};

	inline GRAVLib::uint32 texture2D::getWidth() const { return m_Width; }
	inline GRAVLib::uint32 texture2D::getHeight() const { return m_Height; }
	inline GRAVLib::uint32 texture2D::getRendererID() const { return m_RendererID; }
}