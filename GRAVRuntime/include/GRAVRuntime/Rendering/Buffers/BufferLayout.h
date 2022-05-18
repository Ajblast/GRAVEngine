#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Rendering/Buffers/BufferElement.h"
#include <vector>
#include <initializer_list>

namespace GRAVRuntime::Rendering::Buffers
{
	// A buffer that has multiple elements that can be of different types and sizes.
		// Describes the layout of a buffer of memory
		// Tied directly to a vertex buffer
	class GRAVRuntimeAPI bufferLayout
	{
	public:
		bufferLayout();
		bufferLayout(std::initializer_list<bufferElement> elements);

		// Get the layout stride
		GRAVLib::uint32 getStride() const;
		// Get the elements of the buffer
		const std::vector<bufferElement>& getElements() const;

		std::vector<bufferElement>::iterator begin();
		std::vector<bufferElement>::iterator end();
		std::vector<bufferElement>::const_iterator begin() const;
		std::vector<bufferElement>::const_iterator end() const;

	private:
		// Calculate the offset and stride of the buffer
		void calculateOffsetAndStride();
	private:
		std::vector<bufferElement> m_Elements;	// The elements
		GRAVLib::uint32 m_Stride = 0;			// Stride of the entire buffer
	};

	inline GRAVLib::uint32 bufferLayout::getStride() const { return m_Stride; }
	inline const std::vector<bufferElement>& bufferLayout::getElements() const { return m_Elements; }

	inline std::vector<bufferElement>::iterator bufferLayout::begin() { return m_Elements.begin(); }
	inline std::vector<bufferElement>::iterator bufferLayout::end() { return m_Elements.end(); }
	inline std::vector<bufferElement>::const_iterator bufferLayout::begin() const { return m_Elements.begin(); }
	inline std::vector<bufferElement>::const_iterator bufferLayout::end() const { return m_Elements.end(); }

}