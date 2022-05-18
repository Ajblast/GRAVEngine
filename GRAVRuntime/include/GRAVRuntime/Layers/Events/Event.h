#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include "GRAVRuntime/Layers/Events/EventType.h"
#include "GRAVRuntime/Layers/Events/EventCategory.h"
#include <string>

namespace GRAVRuntime::Layers::Events
{
	#define EVENT_CLASS_TYPE(type) static GRAVRuntime::Layers::Events::eventType getStaticType() { return GRAVRuntime::Layers::Events::eventType::type; }\
								virtual GRAVRuntime::Layers::Events::eventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override {return category;}

	class GRAVRuntimeAPI event
	{
	public:
		event();
		virtual ~event();

		virtual eventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual GRAVLib::int32 getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		bool isInCategory(eventCategory category) { return getCategoryFlags() & category; }

	public:
		bool m_Handled;
	};
}