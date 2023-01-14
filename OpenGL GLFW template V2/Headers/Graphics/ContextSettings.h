#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

namespace jf
{

	class ContextSettings
	{
	public:
		ContextSettings(int depthBits, int stencilBits, int antiAliasing, int minor, int major)
			: depthBits(depthBits), stencilBits(stencilBits),
			antiAliasing(antiAliasing), minor(minor), major(major)
		{ }

		ContextSettings()
		{ }

		int depthBits = 24;
		int stencilBits = 8;
		int antiAliasing = 0;
		int minor = 1;
		int major = 2;
		int refreshRate = 0;
		int profile = GLFW_OPENGL_CORE_PROFILE;

		bool floating = false;
		bool resizable = true;
		bool decorated = true;
		bool transparent = false;
		bool sRGB = false;
	};

}