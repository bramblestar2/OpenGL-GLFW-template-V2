#include <iostream>
#include "Headers/Graphics/Window.h"

void error_callback(int error, const char* msg)
{
    std::string s;
    s = " [" + std::to_string(error) + "] " + msg + '\n';
    std::cerr << s << std::endl;
}

int main()
{
    if (!glfwInit())
        return -1;

    glfwSetErrorCallback(error_callback);

    jf::ContextSettings settings(24, 8, 0, 1, 2);
    jf::Window window(100, 100, "Title", settings);

    while (window.isOpen())
    {
        jf::Event event;
        while (window.poll_events(event))
        {

        }

        window.clear();

        window.display();
    }
}