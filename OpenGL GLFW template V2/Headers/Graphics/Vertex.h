#pragma once
#include "../System/Vector3.h"

namespace jf
{

	struct Vertex
	{
		Vertex();
		float* data[12];

		float x = 0, y = 0, z = 0;
		float r = 0, g = 0, b = 0, a = 1;
		float texY = 0, texX = 0;
		float normalX = 0, normalY = 0, normalZ = -1;
	};

}