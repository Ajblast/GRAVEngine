#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/IO/MouseCodes.h"
#include "GRAVRuntime/Layers/Events/Event.h"
#include <format>

namespace GRAVRuntime::Layers::Events
{
	class GRAVRuntimeAPI mouseEvent : public event
	{
	public:
		virtual ~mouseEvent();

		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput);
	};

	class GRAVRuntimeAPI mouseMovedEvent : public mouseEvent
	{
	public:
		mouseMovedEvent(const float x, const float y);
		virtual ~mouseMovedEvent();

		float getX() const;
		float getY() const;

		EVENT_CLASS_TYPE(mouseMoved);
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput);
	private:
		float m_MouseX, m_MouseY;
	};
	class GRAVRuntimeAPI mouseScrolledEvent : public mouseEvent
	{
	public:
		mouseScrolledEvent(const float xOffset, const float yOffset);
		virtual ~mouseScrolledEvent();

		float getXOffset() const;
		float getYOffset() const;

		EVENT_CLASS_TYPE(mouseScrolled);
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput);
	private:
		float m_XOffset, m_YOffset;
	};

	class GRAVRuntimeAPI mouseButtonEvent : public mouseEvent
	{
	public:
		virtual ~mouseButtonEvent();

		IO::mouseCode getMouseButton() const;

		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput | eventCategoryMouseButton);
	protected:
		mouseButtonEvent(const IO::mouseCode button);

		IO::mouseCode m_Button;
	};
	class GRAVRuntimeAPI mouseButtonPressedEvent : public mouseButtonEvent
	{
	public:
		mouseButtonPressedEvent(const IO::mouseCode button);
		virtual ~mouseButtonPressedEvent();

		EVENT_CLASS_TYPE(mouseButtonPressed);
	};
	class GRAVRuntimeAPI mouseButtonReleasedEvent : public mouseButtonEvent
	{
	public:
		mouseButtonReleasedEvent(const IO::mouseCode button);
		virtual ~mouseButtonReleasedEvent();

		EVENT_CLASS_TYPE(mouseButtonReleased);
	};

	inline float mouseMovedEvent::getX() const { return m_MouseX; }
	inline float mouseMovedEvent::getY() const { return m_MouseY; }

	inline float mouseScrolledEvent::getXOffset() const { return m_XOffset; }
	inline float mouseScrolledEvent::getYOffset() const { return m_YOffset; }

	inline IO::mouseCode mouseButtonEvent::getMouseButton() const { return m_Button; }
}

template<>
struct std::formatter<GRAVRuntime::Layers::Events::mouseMovedEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::mouseMovedEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[X: {}, Y: {}]", event.m_MouseX, event.m_MouseY);
	}
};
template<>
struct std::formatter<GRAVRuntime::Layers::Events::mouseScrolledEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::mouseScrolledEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[X: {}, Y: {}]", event.m_XOffset, event.m_YOffset);
	}
};
template<>
struct std::formatter<GRAVRuntime::Layers::Events::mouseButtonEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::mouseButtonEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[Button: {}]", event.m_Button);
	}
};