#pragma once
#include "Vertex.h"
#include <vector>
#include <exception>

namespace jf
{

	class VertexArray
	{
	public:
		VertexArray(const std::vector<Vertex> verticies);
		VertexArray();

		void add(const Vertex vertex);
		void remove(const int index);

		int count();
		std::vector<Vertex> m_verticies;

		/* Subscript Operator */
		Vertex* operator[](int index);
	};

}