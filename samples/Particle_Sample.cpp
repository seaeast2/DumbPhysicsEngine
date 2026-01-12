
#include <iostream>
#include "particle.h"
#include <GLFW/glfw3.h>

int main()
{
    // GLFW 초기화
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 창 생성
    GLFWwindow* window = glfwCreateWindow(800, 480, "Particle Sample", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트 설정
    glfwMakeContextCurrent(window);

    Particle particle;
    std::cout << "Particle Sample" << std::endl;

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        // 화면 클리어
        glClear(GL_COLOR_BUFFER_BIT);

        // 이벤트 처리
        glfwPollEvents();

        // 버퍼 스왑
        glfwSwapBuffers(window);
    }

    // 정리
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}