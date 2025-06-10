#include <memory>
#include <iostream>

#include "HelloWindow.h"
#include "HelloTriangle.h"

int main()
{
    auto pOpenGLExp = std::make_unique<OpenGLHelloWindow>();
    return pOpenGLExp->main();
}
