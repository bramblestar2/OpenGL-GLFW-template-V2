#pragma once
//#include "../System/Vector3.h"
#include <glm/glm.hpp>

namespace jf
{

	//struct Vertex
	//{
	//	Vertex();
	//	float* data[12];
	//
	//	float x = 0, y = 0, z = 0;
	//	float r = 0, g = 0, b = 0, a = 1;
	//	float texY = 0, texX = 0;
	//	float normalX = 0, normalY = 0, normalZ = -1;
	//};

	struct Vertex
	{
		glm::vec3 position{ 0,0,0 };
		glm::vec4 color{ 0,0,0,1 };
		glm::vec3 normal{ 0,0,-1 };
		glm::vec2 texture{ 0,0 };
	};

}