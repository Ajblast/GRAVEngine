#pragma once

#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/IO/KeyCodes.h"
#include "GRAVRuntime/Layers/Events/Event.h"
#include <format>

namespace GRAVRuntime::Layers::Events
{
	class GRAVRuntimeAPI windowResizeEvent : public event
	{
	public:
		windowResizeEvent(unsigned int width, unsigned int height);
		virtual ~windowResizeEvent();

		unsigned int getWidth() const;
		unsigned int getHeight() const;

		EVENT_CLASS_TYPE(windowResize);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	private:
		unsigned int m_Width, m_Height;
	};
	class GRAVRuntimeAPI windowCloseEvent : public event
	{
	public:
		virtual ~windowCloseEvent();

		EVENT_CLASS_TYPE(windowClose);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	};


	class GRAVRuntimeAPI appTickEvent : public event
	{
	public:
		virtual ~appTickEvent();

		EVENT_CLASS_TYPE(appTick);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	};
	class GRAVRuntimeAPI appUpdateEvent : public event
	{
	public:
		virtual ~appUpdateEvent();

		EVENT_CLASS_TYPE(appUpdate);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	};
	class GRAVRuntimeAPI appRenderEvent : public event
	{
	public:
		virtual ~appRenderEvent();

		EVENT_CLASS_TYPE(appRender);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	};

	inline unsigned int windowResizeEvent::getWidth() const { return m_Width; }
	inline unsigned int windowResizeEvent::getHeight() const { return m_Height; }
}

template<>
struct std::formatter<GRAVRuntime::Layers::Events::windowResizeEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::windowResizeEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[Width: {} | Height: {}]", event.m_Width, event.m_Height);
	}
};
