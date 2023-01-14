#pragma once

namespace jf
{

	class Color
	{
	public:
		Color(float r, float g, float b, float a = 255)
			: r(r), g(g), b(b), a(a)
		{ }

		float r = 0;
		float g = 0;
		float b = 0;
		float a = 0;
	};

}