#include "HelloWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int OpenGLHelloWindow::main()
{
	beginOpenGL();

	auto window = createWindow();
	if (window == nullptr)
	{
		return -1;
	}

	befordRenderLoop();
	renderLoop(window);
	afterRenderLoop();

	endOpenGL();
    return 0;
}

int OpenGLHelloWindow::beginOpenGL() const {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    return 0;
}

int OpenGLHelloWindow::initGLAD() const {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	return 0;
}

GLFWwindow* OpenGLHelloWindow::createWindow(const unsigned int width, const unsigned int height) const {
	// create window[���ڴ���]
	GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return nullptr;
	}
	// Make the context of our window the main context on the current thread.
	// [��������������Ϊ�߳���������]
	glfwMakeContextCurrent(window);

	// init GLAD
	if (initGLAD())
	{
		return nullptr;
	}

	// Tell OpenGL the size of the rendering window[֪ͨOpenGL���ڵĴ�С]
	glViewport(0, 0, width, height);
	// Register a callback function on the windows
	// (Whenever the window changes in size, GLFW calls this function and fills in the proper arguments for you to process.)
	// [���ô��ڴ�С�ص��������ڴ�С�仯ʱ���ͻ�������ص�������֪ͨOpenGL�´��ڴ�С]
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    return window;
}

void OpenGLHelloWindow::endOpenGL() const {
	//[��Դ�ͷ�]
	glfwTerminate();
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

void OpenGLHelloWindow::renderLoop(GLFWwindow* window)
{
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
}