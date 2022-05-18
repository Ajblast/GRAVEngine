#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Shaders/Shader.h"
#include <string>
#include <unordered_map>

namespace GRAVRuntime::Rendering::Shaders
{
	// Simple library to hold shaders
	class GRAVRuntimeAPI shaderManager : public GRAVLib::singleton<shaderManager>
	{
	public:
		virtual ~shaderManager();

		// Add a shader to this library
		void add(const std::string& name, const GRAVLib::ref<shader>& shader);
		// Add a shader to this library
		void add(const GRAVLib::ref<shader>& shader);

		// Create a shader from the file path and load it into the library
		GRAVLib::ref<shader> load(const std::string& filepath);
		// Create a shader from the file path and load it into the library
		GRAVLib::ref<shader> load(const std::string& name, const std::string& filepath);

		GRAVLib::ref<shader> get(const std::string& name);

		bool exists(const std::string& name) const;

		GRAVLib_SINGLETON_INSTANCE(shaderManager);
	private:
		// TODO: Change to allow memory management
		std::unordered_map<std::string, GRAVLib::ref<shader>> m_Shaders;
	};
}
