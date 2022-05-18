#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include <array>

namespace GRAVRuntime::IO
{
	// WARNING! Any changes to this enum requires a change in the coresponding  iterable mousecode array

	// Mouse Codes
	enum class mouseCode: GRAVLib::uint16
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	};

	// Iterable Mouse Codes
	const std::array<mouseCode, 8> g_mouseCode = {
		mouseCode::Button0,
		mouseCode::Button1,
		mouseCode::Button2,
		mouseCode::Button3,
		mouseCode::Button4,
		mouseCode::Button5,
		mouseCode::Button6,
		mouseCode::Button7
	};
}