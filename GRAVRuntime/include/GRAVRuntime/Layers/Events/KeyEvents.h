#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/IO/KeyCodes.h"
#include "GRAVRuntime/Layers/Events/Event.h"
#include <format>

namespace GRAVRuntime::Layers::Events
{
	// Event that is called for keys
	class GRAVRuntimeAPI keyEvent : public event
	{
	public:
		virtual ~keyEvent();
		IO::keyCode getKeyCode() const;

		EVENT_CLASS_CATEGORY(eventCategoryKeyboard | eventCategoryInput);
	protected:
		keyEvent(const IO::keyCode keyCode);

		IO::keyCode m_KeyCode;
	};

	// Event that is called when a key is pressed
	class GRAVRuntimeAPI keyPressedEvent : public keyEvent
	{
	public:
		keyPressedEvent(const IO::keyCode keycode, const GRAVLib::uint16 repeatCount);
		virtual ~keyPressedEvent();

		GRAVLib::uint16 getRepeatCount() const;

		EVENT_CLASS_TYPE(keyPressed)
	private:
		GRAVLib::uint16 m_RepeatCount;
	};

	// Event that is called when a key is released
	class GRAVRuntimeAPI keyReleasedEvent : public keyEvent
	{
	public:
		keyReleasedEvent(const IO::keyCode keycode);
		virtual ~keyReleasedEvent();

		EVENT_CLASS_TYPE(keyReleased);
	};

	// Event that is called when a key is typed
	class GRAVRuntimeAPI keyTypedEvent : public keyEvent
	{
	public:
		keyTypedEvent(const IO::keyCode keycode);
		virtual ~keyTypedEvent();

		EVENT_CLASS_TYPE(keyTyped);
	};


	inline IO::keyCode keyEvent::getKeyCode() const { return m_KeyCode; }
	inline GRAVLib::uint16 keyPressedEvent::getRepeatCount() const { return m_RepeatCount; }
}

template<>
struct std::formatter<GRAVRuntime::Layers::Events::keyEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::keyEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[KeyCode: {}]", event.m_KeyCode);
	}
};
template<>
struct std::formatter<GRAVRuntime::Layers::Events::keyPressedEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::keyPressedEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[KeyCode: {} | RepeatCount: {}]", event.m_KeyCode, event.m_RepeatCount);
	}
};
template<>
struct std::formatter<GRAVRuntime::Layers::Events::keyReleasedEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::keyReleasedEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[KeyCode: {}]", event.m_KeyCode);
	}
};
template<>
struct std::formatter<GRAVRuntime::Layers::Events::keyTypedEvent> : std::formatter<std::string_view>
{
	template<typename FormatContext>
	auto format(const GRAVRuntime::Layers::Events::keyTypedEvent& event, FormatContext& ctx)
	{
		return format_to(ctx.out(), "[KeyCode: {}]", event.m_KeyCode);
	}
};
