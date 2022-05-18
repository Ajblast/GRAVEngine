#include "GRAVRuntime/Layers/Events/ApplicationEvents.h"

GRAVRuntime::Layers::Events::windowResizeEvent::windowResizeEvent(unsigned int width, unsigned int height) :
	m_Width(width), m_Height(height) 
{}
GRAVRuntime::Layers::Events::windowResizeEvent::~windowResizeEvent()
{}

GRAVRuntime::Layers::Events::windowCloseEvent::~windowCloseEvent()
{}

GRAVRuntime::Layers::Events::appTickEvent::~appTickEvent()
{}
GRAVRuntime::Layers::Events::appUpdateEvent::~appUpdateEvent()
{}
GRAVRuntime::Layers::Events::appRenderEvent::~appRenderEvent()
{}
