#pragma once

#include "GRAVRuntime/GRAVRuntimeCore.h"
#include <array>

namespace GRAVRuntime::IO
{
	// WARNING! Any changes to this enum requires a change in the coresponding iterable keycode array

	// A key
	enum class keyCode : GRAVLib::uint16
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	};

	// Iterable key codes
	const std::array<keyCode, 120> g_keyCode = {
		// From glfw3.h
		keyCode::Space,
		keyCode::Apostrophe,	/* ' */
		keyCode::Comma,		/* , */
		keyCode::Minus,		/* - */
		keyCode::Period,		/* . */
		keyCode::Slash,		/* / */
		keyCode::D0, /* 0 */
		keyCode::D1, /* 1 */
		keyCode::D2, /* 2 */
		keyCode::D3, /* 3 */
		keyCode::D4, /* 4 */
		keyCode::D5, /* 5 */
		keyCode::D6, /* 6 */
		keyCode::D7, /* 7 */
		keyCode::D8, /* 8 */
		keyCode::D9, /* 9 */
		keyCode::Semicolon,	/* ; */
		keyCode::Equal,		/* = */
		keyCode::A,
		keyCode::B,
		keyCode::C,
		keyCode::D,
		keyCode::E,
		keyCode::F,
		keyCode::G,
		keyCode::H,
		keyCode::I,
		keyCode::J,
		keyCode::K,
		keyCode::L,
		keyCode::M,
		keyCode::N,
		keyCode::O,
		keyCode::P,
		keyCode::Q,
		keyCode::R,
		keyCode::S,
		keyCode::T,
		keyCode::U,
		keyCode::V,
		keyCode::W,
		keyCode::X,
		keyCode::Y,
		keyCode::Z,
		keyCode::LeftBracket,  /* [ */
		keyCode::Backslash,	/* \ */
		keyCode::RightBracket, /* ] */
		keyCode::GraveAccent,  /* ` */
		keyCode::World1, /* non-US #1 */
		keyCode::World2, /* non-US #2 */
		/* Function keys */
		keyCode::Escape,
		keyCode::Enter,
		keyCode::Tab,
		keyCode::Backspace,
		keyCode::Insert,
		keyCode::Delete,
		keyCode::Right,
		keyCode::Left,
		keyCode::Down,
		keyCode::Up,
		keyCode::PageUp,
		keyCode::PageDown,
		keyCode::Home,
		keyCode::End,
		keyCode::CapsLock,
		keyCode::ScrollLock,
		keyCode::NumLock,
		keyCode::PrintScreen,
		keyCode::Pause,
		keyCode::F1,
		keyCode::F2,
		keyCode::F3,
		keyCode::F4,
		keyCode::F5,
		keyCode::F6,
		keyCode::F7,
		keyCode::F8,
		keyCode::F9,
		keyCode::F10,
		keyCode::F11,
		keyCode::F12,
		keyCode::F13,
		keyCode::F14,
		keyCode::F15,
		keyCode::F16,
		keyCode::F17,
		keyCode::F18,
		keyCode::F19,
		keyCode::F20,
		keyCode::F21,
		keyCode::F22,
		keyCode::F23,
		keyCode::F24,
		keyCode::F25,
		/* Keypad */
		keyCode::KP0,
		keyCode::KP1,
		keyCode::KP2,
		keyCode::KP3,
		keyCode::KP4,
		keyCode::KP5,
		keyCode::KP6,
		keyCode::KP7,
		keyCode::KP8,
		keyCode::KP9,
		keyCode::KPDecimal,
		keyCode::KPDivide,
		keyCode::KPMultiply,
		keyCode::KPSubtract,
		keyCode::KPAdd,
		keyCode::KPEnter,
		keyCode::KPEqual,
		keyCode::LeftShift,
		keyCode::LeftControl,
		keyCode::LeftAlt,
		keyCode::LeftSuper,
		keyCode::RightShift,
		keyCode::RightControl,
		keyCode::RightAlt,
		keyCode::RightSuper,
		keyCode::Menu
	};
}