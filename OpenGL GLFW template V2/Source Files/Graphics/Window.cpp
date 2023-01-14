#include "../../Headers/Graphics/Window.h"

jf::Window::Window(const int width, const int height, 
	const std::string title, const ContextSettings settings)
{
	m_window = nullptr;
	m_cameraActive = false;
	m_viewActive = false;

	glfwWindowHint(GLFW_DEPTH_BITS, settings.depthBits);
	glfwWindowHint(GLFW_STENCIL_BITS, settings.stencilBits);
	glfwWindowHint(GLFW_SAMPLES, settings.antiAliasing);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, settings.minor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, settings.major);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, settings.profile);
	glfwWindowHint(GLFW_REFRESH_RATE, settings.refreshRate);
	glfwWindowHint(GLFW_RESIZABLE, settings.resizable);
	glfwWindowHint(GLFW_SRGB_CAPABLE, settings.sRGB);
	glfwWindowHint(GLFW_FLOATING, settings.floating);
	glfwWindowHint(GLFW_DECORATED, settings.decorated);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, settings.transparent);

	m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

	//Set position of window to the center of screen
	int count;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	int t_xpos, t_ypos, t_width, t_height;
	glfwGetMonitorWorkarea(monitors[0], &t_xpos, &t_ypos, &t_width, &t_height);
	glfwSetWindowPos(m_window, t_width / 2 - (width / 2), t_height / 2 - (height / 2));
	
	glfwMakeContextCurrent(m_window);
}

jf::Window::~Window()
{
	glfwDestroyWindow(m_window);
}

jf::Vector2i jf::Window::getPosition() const
{
	Vector2i pos;
	glfwGetWindowPos(m_window, &pos.x, &pos.y);
	return pos;
}

jf::Vector2i jf::Window::getSize() const
{
	Vector2i size;
	glfwGetWindowSize(m_window, &size.x, &size.y);
	return size;
}

GLFWwindow* jf::Window::getWindow() const
{
	return m_window;
}

bool jf::Window::isVisible() const
{
	int visible;
	visible = glfwGetWindowAttrib(m_window, GLFW_VISIBLE);
	return visible == 0 ? false : true;
}

bool jf::Window::isFocused() const
{
	int focused;
	focused = glfwGetWindowAttrib(m_window, GLFW_FOCUSED);
	return focused == 0 ? false : true;
}

bool jf::Window::isOpen() const
{
	return glfwWindowShouldClose(m_window) == 0 ? true : false;
}

void jf::Window::setPosition(const int x, const int y)
{
	glfwSetWindowPos(m_window, x, y);
}

void jf::Window::setTitle(const std::string title)
{
	glfwSetWindowTitle(m_window, title.c_str());
}

void jf::Window::setAspectRatio(const int numerator, const int denominator)
{
	glfwSetWindowAspectRatio(m_window, numerator, denominator);
}

void jf::Window::setVisibility(const bool isVisible)
{
	glfwSetWindowAttrib(m_window, GLFW_VISIBLE, isVisible);
}

void jf::Window::useView()
{
	if (m_cameraActive)
		m_cameraActive = false;

	m_viewActive = true;
}

void jf::Window::useCamera()
{
	if (m_viewActive)
		m_viewActive = false;

	m_cameraActive = true;
}

void jf::Window::clear(const Color color)
{
	clear(color.r /255, color.g/255, color.b/255, color.a/255);
}

void jf::Window::clear(const float r, const float g, const float b, const float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void jf::Window::clear()
{
	clear(0, 0, 0, 1);
}

void jf::Window::close()
{
	glfwSetWindowShouldClose(m_window, 1);
}

bool jf::Window::poll_events(Event& event)
{
	glfwPollEvents();
	return false;
}

void jf::Window::display()
{
	if (m_viewActive)
	{
	}
	else if (m_cameraActive)
	{
	}

	glfwSwapBuffers(m_window);
}
