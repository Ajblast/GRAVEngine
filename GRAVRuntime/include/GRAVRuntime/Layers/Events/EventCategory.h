#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"

namespace GRAVRuntime::Layers::Events
{
	enum eventCategory
	{
		none = 0,
		eventCategoryApplication	= GRAVLib_BIT(0),
		eventCategoryInput			= GRAVLib_BIT(1),
		eventCategoryKeyboard		= GRAVLib_BIT(2),
		eventCategoryMouse			= GRAVLib_BIT(3),
		eventCategoryMouseButton	= GRAVLib_BIT(4)
	};
}