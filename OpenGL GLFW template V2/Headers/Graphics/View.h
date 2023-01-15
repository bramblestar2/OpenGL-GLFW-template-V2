#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../System/Vector2.h"

namespace jf
{

	class View
	{
	public:
		View(const Vector2f size, const Vector2f position);
		View();
		
		void setPosition(const jf::Vector2f position);
		void setSize(const jf::Vector2f size);
		void move(const jf::Vector2f offset);

		jf::Vector2f getSize() const;
		jf::Vector2f getPosition() const;

		virtual void update();

	private:
		Vector2f m_size;
		Vector2f m_position;

		bool m_update;
	};

}