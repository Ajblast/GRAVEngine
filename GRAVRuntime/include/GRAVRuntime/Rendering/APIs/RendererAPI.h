#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Buffers/IndexBuffer.h"
#include "GRAVRuntime/Rendering/Buffers/VertexBuffer.h"
#include "GRAVRuntime/Rendering/Buffers/VertexArray.h"
#include "GRAVRuntime/Rendering/Shaders/Shader.h"
#include "GRAVRuntime/Rendering/Textures/Texture2D.h"
#include "GRAVRuntime/Rendering/GraphicsContext.h"
#include <glm/vec4.hpp>

#define GRAVRuntime_GLFW_CONTEXT_VERSION_MAJOR 4
#define GRAVRuntime_GLFW_CONTEXT_VERSION_MINOR 6


namespace GRAVRuntime::Rendering::APIs
{
	using namespace Buffers;
	using namespace Shaders;
	using namespace Textures;

	// Generic interface for a rendering API
	class GRAVRuntimeAPI rendererAPI : public GRAVLib::singleton<rendererAPI>
	{
	public:
		rendererAPI();
		virtual ~rendererAPI();

		// Startup the API
		virtual void startup() = 0;
		// Set the API's viewport
		virtual void setViewport(GRAVLib::uint32 x, GRAVLib::uint32 y, GRAVLib::uint32 width, GRAVLib::uint32 height) = 0;

		// Set the API's clear color
		virtual void setClearColor(const glm::vec4& color) = 0;
		// Clear the viewport
		virtual void clear() = 0;

		// Draw a vertex array by indices
		virtual void drawIndexed(const GRAVLib::ref<vertexArray>& vertexArray, GRAVLib::uint32 indexCount = 0) = 0;


		#pragma region FactoryMethods
		virtual GRAVLib::ref<indexBuffer> createIndexBuffer(GRAVLib::uint32* indices, GRAVLib::uint32 count) = 0;
		virtual GRAVLib::ref<vertexBuffer> createVertexBuffer(GRAVLib::uint32 size) = 0;
		virtual GRAVLib::ref<vertexBuffer> createVertexBuffer(float* vertices, GRAVLib::uint32 size) = 0;
		virtual GRAVLib::ref<vertexArray> createVertexArray() = 0;

		// Create a shader from a file
		virtual GRAVLib::ref<shader> createShader(const std::string& filePath) = 0;
		// Create a shader with a vertex and fragment string
		virtual GRAVLib::ref<shader> createShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) = 0;

		virtual GRAVLib::ref<texture2D> createTexture(GRAVLib::uint32 width, GRAVLib::uint32 height) = 0;
		virtual GRAVLib::ref<texture2D> createTexture(const std::string& path) = 0;

		virtual GRAVLib::scope<graphicsContext> createContext(void* window) = 0;
		#pragma endregion

		GRAVLib_SINGLETON_INSTANCE(rendererAPI);
	};
}