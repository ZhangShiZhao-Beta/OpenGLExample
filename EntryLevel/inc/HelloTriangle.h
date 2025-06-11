#pragma once
#include "HelloWindow.h"
class GLFWwindow;

class OpenGLHelloTriangle : public OpenGLHelloWindow
{
protected:
	void renderLoop(GLFWwindow* window) override;
};