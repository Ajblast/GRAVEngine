#include "GRAVRuntime/Layers/Events/KeyEvents.h"

GRAVRuntime::Layers::Events::keyEvent::keyEvent(const IO::keyCode keyCode) : 
	m_KeyCode(keyCode)
{}
GRAVRuntime::Layers::Events::keyEvent::~keyEvent()
{}

GRAVRuntime::Layers::Events::keyPressedEvent::keyPressedEvent(const IO::keyCode keycode, const GRAVLib::uint16 repeatCount) :
	keyEvent(keycode), m_RepeatCount(repeatCount)
{}
GRAVRuntime::Layers::Events::keyPressedEvent::~keyPressedEvent()
{}

GRAVRuntime::Layers::Events::keyReleasedEvent::keyReleasedEvent(const IO::keyCode keycode) :
	keyEvent(keycode)
{}
GRAVRuntime::Layers::Events::keyReleasedEvent::~keyReleasedEvent()
{}

GRAVRuntime::Layers::Events::keyTypedEvent::keyTypedEvent(const IO::keyCode keycode) :
	keyEvent(keycode)
{}
GRAVRuntime::Layers::Events::keyTypedEvent::~keyTypedEvent()
{}
