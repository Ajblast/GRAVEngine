#pragma once

#ifdef GRAVRuntime_EXPORTS
	#define GRAVRuntimeAPI __declspec(dllexport)
#else
	#define GRAVRuntimeAPI __declspec(dllimport)
#endif
