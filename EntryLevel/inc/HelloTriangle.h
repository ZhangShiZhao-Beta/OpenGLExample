#pragma once
#include "HelloWindow.h"
class GLFWwindow;

class OpenGLHelloTriangle : public OpenGLHelloWindow
{
public:
	int main() override;
protected:
	void befordRenderLoop() override {}
	void renderLoop(GLFWwindow* window) override {}
	void afterRenderLoop() override {}
};