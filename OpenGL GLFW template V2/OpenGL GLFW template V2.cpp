#include <iostream>
#include "Headers/Graphics/Window.h"
#include "Headers/Graphics/View.h"

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
    jf::Window window(500, 300, "Title", settings);

    if (glewInit() != GLEW_OK)
        return -1;

    jf::View view({500, 300}, {0,0});

    while (window.isOpen())
    {
        jf::Event event;
        while (window.poll_events(event))
        {
            if (event.type == jf::Event::KEY_EVENT)
            {
                if (event.keys.key == GLFW_KEY_ESCAPE)
                    window.close();
            }
        }

        double xpos, ypos;
        glfwGetCursorPos(window.getWindow(), &xpos, &ypos);

        printf(std::string(std::to_string(xpos) + " - " + std::to_string(ypos) + "\n").c_str());

        window.clear();

        glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2f(0,0);
        glColor3f(1, 1, 0);
        glVertex2f(100,0);
        glColor3f(1, 0, 0);
        glVertex2f(100,100);
        glColor3f(0, 1, 0);
        glVertex2f(0,100);
        glEnd();

        view.update();
        window.display();
    }

    glfwTerminate();
}