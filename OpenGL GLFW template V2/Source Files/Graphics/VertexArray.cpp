#include "../../Headers/Graphics/VertexArray.h"
#include <iostream>

jf::VertexArray::VertexArray(const std::vector<Vertex> verticies)
{
    this->m_verticies = verticies;
}

jf::VertexArray::VertexArray()
{
}

void jf::VertexArray::add(const Vertex vertex)
{
    m_verticies.push_back(vertex);
}

void jf::VertexArray::remove(const int index)
{
    if (index < 0)
        throw std::out_of_range("Index out of range : Less than 0\n");
    else if (index > count() - 1)
        throw std::out_of_range("Index out of range : Greater than m_verticies size");
    else
        m_verticies.erase(m_verticies.begin() + index);
}

int jf::VertexArray::count()
{
    return m_verticies.size();
}

jf::Vertex* jf::VertexArray::operator[](int index)
{
    return &m_verticies.at(index);
}
