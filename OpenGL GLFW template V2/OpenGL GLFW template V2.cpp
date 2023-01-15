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
    jf::Vertex vertex;
    vertex.x = 5;

    for (int i = 0; i < 12; i++)
        std::cout << *vertex.data[i] << std::endl;

    if (!glfwInit())
        return -1;

    glfwSetErrorCallback(error_callback);

    jf::ContextSettings settings(24, 8, 0, 3, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    jf::Window window(300, 300, "Title", settings);

    if (glewInit() != GLEW_OK)
        return -1;

    jf::View view({ 500, 300 }, { 0,0 });

    float square[] =
    {
        -0.5f, -0.5f, 0.0f,   1.f, 0.f, 0.f,
        -0.5f, 0.5f,  0.0f,   0.f, 0.f, 1.f,
        0.5f, 0.5f,   0.0f,   0.f, 1.f, 0.f,

        -0.5f, -0.5f, 0.0f,   1.f, 0.f, 0.f,
        0.5f, 0.5f,  0.0f,    0.f, 1.f, 0.f,
        0.5f, -0.5f,   0.0f,  0.f, 0.f, 1.f,
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Shader shader("2dShader.vert", "2dShader.frag");

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
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);


        window.display();
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}