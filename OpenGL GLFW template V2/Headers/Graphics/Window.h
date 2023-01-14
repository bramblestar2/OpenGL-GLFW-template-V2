#pragma once
#include <string>
#include "../../GLFW Header.h"
#include "../System/Vector2.h"
#include "../Graphics/ContextSettings.h"
#include "../Graphics/Color.h"
#include "Event.h"
#include "EventHandler.h"

namespace jf 
{

	class Window
	{
	public:
		Window(const int width, const int height, const std::string title,
			const ContextSettings settings = ContextSettings(24, 8, 0, 1, 2));
		virtual ~Window();

		/* Gets */
		Vector2i getPosition() const;
		Vector2i getSize() const;
		GLFWwindow* getWindow() const; //Gets the GLFW Window
		bool isVisible() const;
		bool isFocused() const;
		bool isOpen() const;

		/* Sets */
		void setPosition(const int x, const int y);
		void setTitle(const std::string title);
		void setAspectRatio(const int numerator, const int denominator);
		void setVisibility(const bool isVisible);
		void setDecorated(const bool isDecorated);

		void useView();
		void useCamera();

		void clear(const Color color);
		void clear(const float r, const float g, const float b, const float a = 255);
		void clear();
		void close();

		bool poll_events(Event& event);

		virtual void display();

	private:
		GLFWwindow* m_window;

		EventHandler m_event_handler;

		bool m_viewActive;
		bool m_cameraActive;
	};

}