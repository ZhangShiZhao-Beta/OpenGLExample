#pragma once
#include "OpenGLExampleBase.h"
class GLFWwindow;

class OpenGLHelloWindow : public OpenGLExampleBase
{
public:
	int main() override;

private:
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	static void processInput(GLFWwindow* window);
};