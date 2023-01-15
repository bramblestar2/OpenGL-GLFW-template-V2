#include "../../Headers/Graphics/View.h"
#include "../../GLFW Header.h"

jf::View::View(const Vector2f size, const Vector2f position)
	: m_size(size), m_position(position)
{
	m_update = true;
}

jf::View::View() : m_size(jf::Vector2f(1, 1)), m_position(jf::Vector2f())
{
	m_update = true;
}

void jf::View::setPosition(const jf::Vector2f position)
{
	m_position = position;
	m_update = true;
}

void jf::View::setSize(const jf::Vector2f size)
{
	m_size = size;
	m_update = true;
}

void jf::View::move(const jf::Vector2f offset)
{
	m_position.x += offset.x;
	m_position.y += offset.y;
	m_update = true;
}

jf::Vector2f jf::View::getSize() const
{
	return m_size;
}

jf::Vector2f jf::View::getPosition() const
{
	return m_position;
}

void jf::View::update()
{
	if (m_update)
	{
		glViewport(m_position.x, m_position.y, m_size.x, m_size.y);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, m_size.x, m_size.y, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		m_update = false;
	}
}
