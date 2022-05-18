#include "GRAVRuntime/Rendering/Windows/Window.h"

#ifdef GRAVLib_PLATFORM_WINDOWS
#include "GRAVRuntime/Platform/Windows/WindowsWindow.h"
#endif

GRAVRuntime::Rendering::window::~window() 
{}

void GRAVRuntime::Rendering::window::bindGraphicsContext() 
{
	m_Context->bind();
}
void GRAVRuntime::Rendering::window::unbindGraphicsContext()
{
	m_Context->unbind();
}

GRAVLib::scope<GRAVRuntime::Rendering::window> GRAVRuntime::Rendering::window::create(const GRAVRuntime::Rendering::windowProperties& properties)
{
	#ifdef GRAVLib_PLATFORM_WINDOWS
	return GRAVLib::createScope<windowsWindow>(properties);
	#else
	GRAV_ASSERT_TRUE(false); // Unable to create window
	return nullptr;
	#endif
}