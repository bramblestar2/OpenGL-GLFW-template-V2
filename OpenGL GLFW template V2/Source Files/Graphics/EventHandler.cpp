#include "../../Headers/Graphics/EventHandler.h"

std::vector<jf::Event> jf::EventHandler::eventList;

jf::EventHandler::~EventHandler()
{
	if (topEvent.type == Event::EventType::DROP_EVENT)
		if (topEvent.drop.count != 0)
			delete[] topEvent.drop.paths;

	for (int i = 0; i < eventList.size(); i++)
		if (eventList.at(i).type == Event::EventType::DROP_EVENT)
		{
			delete[] eventList.at(i).drop.paths;
		}
}

void jf::EventHandler::pop_event()
{
	if (!isEmpty())
	{
		if (topEvent.type == Event::EventType::DROP_EVENT)
			if (topEvent.drop.count != 0)
				delete[] topEvent.drop.paths;

		topEvent = eventList.at(eventsQueued()-1);
		eventList.pop_back();
	}
}

int jf::EventHandler::eventsQueued() const
{
	return eventList.size();
}

bool jf::EventHandler::isEmpty() const
{
	return eventList.empty();
}

jf::Event jf::EventHandler::top_event() const
{
	return topEvent;
}

void jf::EventHandler::setWindowCallbacks(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetCharCallback(window, character_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetCursorEnterCallback(window, cursor_enter_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetJoystickCallback(joystick_callback);
	glfwSetDropCallback(window, drop_callback);

	glfwSetWindowCloseCallback(window, window_close_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetWindowContentScaleCallback(window, window_content_scale_callback);
	glfwSetWindowPosCallback(window, window_pos_callback);
	glfwSetWindowIconifyCallback(window, window_iconify_callback);
	glfwSetWindowMaximizeCallback(window, window_maximize_callback);
	glfwSetWindowFocusCallback(window, window_focus_callback);
	glfwSetWindowRefreshCallback(window, window_refresh_callback);
}

void jf::EventHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Event event;
	event.keys.key = key;
	event.keys.scancode = scancode;
	event.keys.action = action;
	event.keys.mods = mods;
	event.type = Event::KEY_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::character_callback(GLFWwindow* window, unsigned int codepoint)
{
	Event event;
	event.character.codepoint = codepoint;
	event.type = Event::CHARACTER_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Event event;
	event.cursorMoved.xpos = xpos;
	event.cursorMoved.ypos = ypos;
	event.type = Event::CURSOR_MOVED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::cursor_enter_callback(GLFWwindow* window, int entered)
{
	Event event;
	event.cursorEntered.entered = entered;
	event.type = Event::CURSOR_ENTERED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Event event;
	event.mouseButton.button = button;
	event.mouseButton.action = action;
	event.mouseButton.mods = mods;
	event.type = Event::MOUSE_BUTTON_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Event event;
	event.mouseScroll.xoffset = xoffset;
	event.mouseScroll.yoffset = yoffset;
	event.type = Event::MOUSE_SCROLL_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::joystick_callback(int jid, int event)
{
	Event t_event;
	t_event.joystick.jid = jid;
	t_event.joystick.event = event;
	t_event.type = Event::JOYSTICK_EVENT;
	eventList.push_back(t_event);
}

void jf::EventHandler::drop_callback(GLFWwindow* window, int count, const char** paths)
{
	Event event;
	
	event.drop.count = count;

	event.drop.paths = count != 0 ? new std::string[count] : nullptr;
	for (int i = 0; i < count; i++)
		event.drop.paths[i] = paths[i];

	event.type = Event::DROP_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_close_callback(GLFWwindow* window)
{
	Event event;
	event.type = Event::CLOSED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_size_callback(GLFWwindow* window, int width, int height)
{
	Event event;
	event.sizeChanged.width = width;
	event.sizeChanged.height = height;
	event.type = Event::SIZE_CHANGED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Event event;
	event.bufferChanged.width = width;
	event.bufferChanged.height = height;
	event.type = Event::BUFFER_CHANGED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_content_scale_callback(GLFWwindow* window, float xscale, float yscale)
{
	Event event;
	event.scaleChanged.xscale = xscale;
	event.scaleChanged.yscale = yscale;
	event.type = Event::SCALE_CHANGED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_pos_callback(GLFWwindow* window, int xpos, int ypos)
{
	Event event;
	event.windowMoved.xpos = xpos;
	event.windowMoved.ypos = ypos;
	event.type = Event::WINDOW_MOVED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_iconify_callback(GLFWwindow* window, int iconified)
{
	Event event;
	event.iconified.iconified = iconified;
	event.type = Event::ICONIFIED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_maximize_callback(GLFWwindow* window, int maximized)
{
	Event event;
	event.maximized.maximized = maximized;
	event.type = Event::MAXIMIZED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_focus_callback(GLFWwindow* window, int focused)
{
	Event event;
	event.focused.focused = focused;
	event.type = Event::FOCUSED_EVENT;
	eventList.push_back(event);
}

void jf::EventHandler::window_refresh_callback(GLFWwindow* window)
{
	Event event;
	event.type = Event::REFRESH_EVENT;
	eventList.push_back(event);
}
