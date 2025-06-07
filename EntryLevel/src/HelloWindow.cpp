#include "HelloWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int OpenGLHelloWindow::main()
{
    // Status Settings[״̬����]
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window[���ڴ���]
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Make the context of our window the main context on the current thread.
    // [��������������Ϊ�߳���������]
    glfwMakeContextCurrent(window);

    // init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Tell OpenGL the size of the rendering window[֪ͨOpenGL���ڵĴ�С]
    glViewport(0, 0, 800, 600);

    // Register a callback function on the windows
    // (Whenever the window changes in size, GLFW calls this function and fills in the proper arguments for you to process.)
    // [���ô��ڴ�С�ص��������ڴ�С�仯ʱ���ͻ�������ص�������֪ͨOpenGL�´��ڴ�С]
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input control in GLFW
        processInput(window);

        // output render to the screen[����Ⱦ�������Ļ]
        glfwSwapBuffers(window);

        // check events[����Ƿ����¼�������]
        glfwPollEvents();
    }

    // clean/delete all of GLFW's resources
    //[��Դ�ͷ�]
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