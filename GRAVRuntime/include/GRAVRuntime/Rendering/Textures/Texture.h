#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"

namespace GRAVRuntime::Rendering::Textures
{
	class GRAVRuntimeAPI texture
	{
	public:
		virtual ~texture();

		// Get Texture Width
		virtual GRAVLib::uint32 getWidth() const = 0;
		// Get Texture Height
		virtual GRAVLib::uint32 getHeight() const = 0;
		// Get Texture RendererID
		virtual GRAVLib::uint32 getRendererID() const = 0;

		// Set Texture Data
		virtual void setData(void* data, GRAVLib::uint32 size) = 0;

		// Bind a texture slot
		virtual void bind(GRAVLib::uint32 slot = 0) const = 0;

		virtual bool operator==(const texture& other) const = 0;
	};

}