#include <memory>
#include <iostream>

#include "HelloWindow.h"

int main()
{
    std::unique_ptr<OpenGLHelloWindow> pOpenGLExp = std::make_unique<OpenGLHelloWindow>();
    return pOpenGLExp->main();
}
