#include "HelloWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int OpenGLHelloWindow::main()
{
    // Status Settings[状态设置]
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window[窗口创建]
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Make the context of our window the main context on the current thread.
    // [窗口上下文设置为线程主上下文]
    glfwMakeContextCurrent(window);

    // init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Tell OpenGL the size of the rendering window[通知OpenGL窗口的大小]
    glViewport(0, 0, 800, 600);

    // Register a callback function on the windows
    // (Whenever the window changes in size, GLFW calls this function and fills in the proper arguments for you to process.)
    // [设置窗口大小回调，当窗口大小变化时，就会出触发回调，重新通知OpenGL新窗口大小]
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input control in GLFW
        processInput(window);

        // output render to the screen[将渲染输出到屏幕]
        glfwSwapBuffers(window);

        // check events[检查是否有事件被触发]
        glfwPollEvents();
    }

    // clean/delete all of GLFW's resources
    //[资源释放]
    glfwTerminate();
    return 0;
}

void OpenGLHelloWindow::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << "Resize Windows: " << width << " , " << height << std::endl;
}

void OpenGLHelloWindow::processInput(GLFWwindow* window)
{
    // if escape key is currently being pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        // glfwWindowShouldClose will true in next loop
        glfwSetWindowShouldClose(window, true);
    }
}