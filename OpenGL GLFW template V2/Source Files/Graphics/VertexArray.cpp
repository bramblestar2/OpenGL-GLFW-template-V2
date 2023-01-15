#include "../../Headers/Graphics/VertexArray.h"
#include <iostream>

jf::VertexArray::VertexArray(const std::vector<Vertex> verticies)
{
    this->m_verticies = verticies;

    updateBuffers();
}

jf::VertexArray::VertexArray()
{
    updateBuffers();
}

jf::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void jf::VertexArray::add(const Vertex vertex)
{
    m_verticies.push_back(vertex);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    updateBuffers();
}

void jf::VertexArray::remove(const int index)
{
    if (index < 0)
        throw std::out_of_range("Index out of range : Less than 0\n");
    else if (index > count() - 1)
        throw std::out_of_range("Index out of range : Greater than m_verticies size");
    else
        m_verticies.erase(m_verticies.begin() + index);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    updateBuffers();
}

int jf::VertexArray::count()
{
    return m_verticies.size();
}

void jf::VertexArray::draw(const GLenum type)
{
    glBindVertexArray(VAO);
    glDrawArrays(type, 0, m_verticies.size());
}

jf::Vertex& jf::VertexArray::operator[](int index)
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    updateBuffers();

    return m_verticies.at(index);
}

void jf::VertexArray::updateBuffers()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, count() * 12 * sizeof(float), m_verticies.data(), GL_DYNAMIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // normal attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);
    // texture attribute
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)(10 * sizeof(float)));
    glEnableVertexAttribArray(3);
}
