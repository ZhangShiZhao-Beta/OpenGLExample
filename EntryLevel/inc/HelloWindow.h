#pragma once
#include "OpenGLExampleBase.h"
class GLFWwindow;

class OpenGLHelloWindow : public OpenGLExampleBase
{
public:
	int main() override;

protected:
	int beginOpenGL() const;
	int initGLAD() const;
	GLFWwindow* createWindow(const unsigned int width = 800, const unsigned int height = 600) const;
	void endOpenGL() const;
	
	virtual void befordRenderLoop() {}
	virtual void renderLoop(GLFWwindow* window);
	virtual void afterRenderLoop() {}

	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	static void processInput(GLFWwindow* window);
};