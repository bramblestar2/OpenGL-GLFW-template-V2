#pragma once
#include <string>

namespace jf
{

	class Event
	{
		struct KeyEvent
		{
			int key; //The key thats been pressed
			int scancode; //The id of a key (can differ from platforms)
			int action; //If the key is pressed, released, or held
			int mods;
		};

		struct CharacterEvent
		{
			int codepoint; //The key thats been pressed
		};

		struct CursorMovedEvent
		{
			double xpos; //X position of mouse
			double ypos; //Y position of mouse
		};

		struct CursorEnteredEvent
		{
			int entered; //The mouse has entered or left the window
		};

		struct MouseButtonEvent
		{
			int button; //What button was pressed
			int action; //If the button is pressed or released
			int mods;
		};

		struct MouseScrollEvent
		{
			double xoffset;
			double yoffset;
		};

		struct JoystickEvent
		{
			int jid;
			int event;
		};

		struct DropEvent
		{
			int count; //The count of the files that were dropped
			std::string* paths; //The paths of the dropped files
		};

		//Window events

		//Window size change
		struct SizeChangedEvent
		{
			int width;
			int height;
		};

		//Frame buffer size change
		struct BufferChangedEvent
		{
			int width;
			int height;
		};

		//Content scale change
		struct ScaleChangedEvent
		{
			float xscale;
			int yscale;
		};

		//Window position moved
		struct WindowMovedEvent
		{
			int xpos;
			int ypos;
		};

		//Window Iconified
		struct IconifiedEvent
		{
			int iconified;
		};

		//Window maximized
		struct MaximizedEvent
		{
			int maximized;
		};

		//Windows focus is changed
		struct FocusedEvent
		{
			int focused;
		};

	public:
		enum EventType
		{
			KEY_EVENT,
			CHARACTER_EVENT,
			CURSOR_MOVED_EVENT,
			CURSOR_ENTERED_EVENT,
			MOUSE_BUTTON_EVENT,
			MOUSE_SCROLL_EVENT,
			JOYSTICK_EVENT,
			DROP_EVENT,

			CLOSED_EVENT,
			SIZE_CHANGED_EVENT,
			BUFFER_CHANGED_EVENT,
			SCALE_CHANGED_EVENT,
			WINDOW_MOVED_EVENT,
			ICONIFIED_EVENT,
			MAXIMIZED_EVENT,
			FOCUSED_EVENT,
			REFRESH_EVENT,
		};

		EventType type;

		union
		{
			KeyEvent keys;
			CharacterEvent character;
			CursorMovedEvent cursorMoved;
			CursorEnteredEvent cursorEntered;
			MouseButtonEvent mouseButton;
			MouseScrollEvent mouseScroll;
			JoystickEvent joystick;
			DropEvent drop;

			SizeChangedEvent sizeChanged;
			BufferChangedEvent bufferChanged;
			ScaleChangedEvent scaleChanged;
			WindowMovedEvent windowMoved;
			IconifiedEvent iconified;
			MaximizedEvent maximized;
			FocusedEvent focused;
		};
	};

}