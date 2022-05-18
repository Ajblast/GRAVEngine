#include "GRAVRuntime/Rendering/Textures/Texture2D.h"

GRAVRuntime::Rendering::Textures::texture2D::texture2D(GRAVLib::uint32 width, GRAVLib::uint32 height) :
	m_Width(width), m_Height(height), m_RendererID(0)
{}
GRAVRuntime::Rendering::Textures::texture2D::texture2D(const std::string& path) :
	m_Width(0), m_Height(0), m_Path(path), m_RendererID(0)
{}
GRAVRuntime::Rendering::Textures::texture2D::~texture2D()
{}
