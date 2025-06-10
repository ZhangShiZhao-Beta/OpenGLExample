# 只放文件路径，没有 PUBLIC、PRIVATE 关键字
find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)

set(HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/OpenGLExampleBase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/HelloWindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/HelloTriangle.h
)

set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenGLExampleBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HelloWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HelloTriangle.cpp
)

add_library(EntryLevel)

target_sources(EntryLevel
    PRIVATE
        ${SOURCE_FILES}
    PUBLIC
        ${HEADER_FILES}
)

target_include_directories(EntryLevel
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(EntryLevel
    PUBLIC  
        glad::glad 
        glfw
)
