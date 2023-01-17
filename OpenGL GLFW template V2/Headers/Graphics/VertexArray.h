#pragma once
#include "Vertex.h"
#include <vector>
#include <exception>
#include <GL/glew.h>

namespace jf
{

	class VertexArray
	{
	public:
		VertexArray(const std::vector<Vertex> verticies);
		VertexArray();
		~VertexArray();

		void add(const Vertex vertex);
		void remove(const int index);
		int count();

		void draw(const GLenum type);


		/* Subscript Operator */
		Vertex& operator[](int index);

	private:
		std::vector<Vertex> m_verticies;

		void updateBuffers();

		unsigned int VBO = NULL, VAO = NULL;
	};

}