#include "GRAVRuntime/Layers/Events/MouseEvents.h"

GRAVRuntime::Layers::Events::mouseEvent::~mouseEvent()
{}

GRAVRuntime::Layers::Events::mouseMovedEvent::mouseMovedEvent(const float x, const float y) :
	m_MouseX(x), m_MouseY(y)
{}
GRAVRuntime::Layers::Events::mouseMovedEvent::~mouseMovedEvent()
{}

GRAVRuntime::Layers::Events::mouseScrolledEvent::mouseScrolledEvent(const float xOffset, const float yOffset) :
	m_XOffset(xOffset), m_YOffset(yOffset)
{}
GRAVRuntime::Layers::Events::mouseScrolledEvent::~mouseScrolledEvent()
{}

GRAVRuntime::Layers::Events::mouseButtonEvent::mouseButtonEvent(const IO::mouseCode button) :
	m_Button(button)
{}
GRAVRuntime::Layers::Events::mouseButtonEvent::~mouseButtonEvent()
{}

GRAVRuntime::Layers::Events::mouseButtonPressedEvent::mouseButtonPressedEvent(const IO::mouseCode button) :
	mouseButtonEvent(button)
{}
GRAVRuntime::Layers::Events::mouseButtonPressedEvent::~mouseButtonPressedEvent()
{}
GRAVRuntime::Layers::Events::mouseButtonReleasedEvent::mouseButtonReleasedEvent(const IO::mouseCode button) :
	mouseButtonEvent(button)
{}
GRAVRuntime::Layers::Events::mouseButtonReleasedEvent::~mouseButtonReleasedEvent()
{}
