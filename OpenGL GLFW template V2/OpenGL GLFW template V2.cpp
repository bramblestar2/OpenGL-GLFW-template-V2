#include <iostream>
#include "Headers/Graphics/Window.h"
#include "Headers/Graphics/View.h"
#include "Headers/Graphics/Shader.h"

#include "Headers/Graphics/VertexArray.h"

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

    jf::ContextSettings settings(24, 8, 0, 3, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    jf::Window window(300, 300, "Title", settings);

    if (glewInit() != GLEW_OK)
        return -1;

    jf::View view({ 500, 300 }, { 0,0 });

    Shader shader("2dShader.vert", "2dShader.frag");

    jf::VertexArray arr;
    arr.add(jf::Vertex{ glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(1.f, 0.f, 0.f, 1.0f) });
    arr.add(jf::Vertex{ glm::vec3(-0.5f, 0.5f,  0.0f), glm::vec4(0.f, 1.f, 0.f, 1.0f) });
    arr.add(jf::Vertex{ glm::vec3(0.5f, 0.5f,   0.0f), glm::vec4(0.f, 0.f, 1.f, 1.0f) });
    arr.add(jf::Vertex{ glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(1.f, 0.f, 0.f, 1.0f) });
    arr.add(jf::Vertex{ glm::vec3(0.5f, -0.5f,  0.0f), glm::vec4(0.f, 1.f, 0.f, 1.0f) });
    arr.add(jf::Vertex{ glm::vec3(0.5f, 0.5f,   0.0f), glm::vec4(0.f, 0.f, 1.f, 1.0f) });

    jf::VertexArray arrTwo;
    arrTwo.add(jf::Vertex{ glm::vec3(-1, -1, 1), glm::vec4(1.f, 0.f, 0.f, 1) });
    arrTwo.add(jf::Vertex{ glm::vec3(-1, 1,  1), glm::vec4(0.f, 0.f, 1.f, 1) });
    arrTwo.add(jf::Vertex{ glm::vec3(1, 1,   1), glm::vec4(0.f, 1.f, 0.f, 1) });
    arrTwo.add(jf::Vertex{ glm::vec3(-1, -1, 1), glm::vec4(1.f, 0.f, 0.f, 1) });
    arrTwo.add(jf::Vertex{ glm::vec3(1, 1,   1), glm::vec4(0.f, 1.f, 0.f, 1) });
    arrTwo.add(jf::Vertex{ glm::vec3(1, -1,  1), glm::vec4(0.f, 0.f, 1.f, 1) });

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

            if (event.type == jf::Event::BUFFER_CHANGED_EVENT)
            {
                glViewport(0, 0, event.sizeChanged.width, event.sizeChanged.height);
            }
        }

        window.clear();

        shader.use();
        arrTwo.draw(GL_TRIANGLES);
        arr.draw(GL_TRIANGLES);

        window.display();
    }

    glfwTerminate();
    return 0;
}