#include "GRAVRuntime/Rendering/Shaders/ShaderManager.h"
#include "GRAVRuntime/Rendering/APIs/RendererAPI.h"

GRAVLib_SINGLETON_SET_INSTANCE(GRAVRuntime::Rendering::Shaders::shaderManager);

GRAVRuntime::Rendering::Shaders::shaderManager::~shaderManager()
{}

void GRAVRuntime::Rendering::Shaders::shaderManager::add(const std::string& name, const GRAVLib::ref<shader>& shader)
{
	GRAV_ASSERT_FALSE(exists(name));

	m_Shaders[name] = shader;
}
void GRAVRuntime::Rendering::Shaders::shaderManager::add(const GRAVLib::ref<shader>& shader)
{
	// Get the shader's name and add it to the library
	const std::string& name = shader->getName();
	add(name, shader);
}

GRAVLib::ref<GRAVRuntime::Rendering::Shaders::shader> GRAVRuntime::Rendering::Shaders::shaderManager::load(const std::string& filepath)
{
	// Create the shader
	auto shader = APIs::rendererAPI::getInstance().createShader(filepath);
	add(shader);
	return shader;
}
GRAVLib::ref<GRAVRuntime::Rendering::Shaders::shader> GRAVRuntime::Rendering::Shaders::shaderManager::load(const std::string& name, const std::string& filepath)
{
	// Create the shader
	auto shader = APIs::rendererAPI::getInstance().createShader(filepath);
	add(name, shader);
	return shader;
}

GRAVLib::ref<GRAVRuntime::Rendering::Shaders::shader> GRAVRuntime::Rendering::Shaders::shaderManager::get(const std::string& name)
{
	// Ensure that this shader exists
	GRAV_ASSERT_TRUE(exists(name));
	return m_Shaders[name];
}

bool GRAVRuntime::Rendering::Shaders::shaderManager::exists(const std::string& name) const
{
	// Find the shader and see if it exists
	return m_Shaders.find(name) != m_Shaders.end();
}