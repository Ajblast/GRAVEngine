#include "GRAVRuntime/Rendering/Buffers/BufferLayout.h"

GRAVRuntime::Rendering::Buffers::bufferLayout::bufferLayout()
{}
GRAVRuntime::Rendering::Buffers::bufferLayout::bufferLayout(std::initializer_list<bufferElement> elements) : m_Elements(elements)
{
	calculateOffsetAndStride();
}

void GRAVRuntime::Rendering::Buffers::bufferLayout::calculateOffsetAndStride()
{
	size_t offset = 0;
	m_Stride = 0;

	// For each element in this buffer
	for (auto& element : m_Elements)
	{
		element.m_Offset = offset;	// Set the element's offset
		offset += element.m_Size;	// Increase the offset for next element
		m_Stride += element.m_Size;	// Increase the total stride of the entire layout
	}
}