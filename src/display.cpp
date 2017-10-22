#include "NEATanks.h"
#include <chrono>
#include <thread>

#define FPS 60

double NEATanks_time;

GLFWwindow* createDisplay() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow* window = glfwCreateWindow(1600, 800, "NEATanks", NULL, NULL);

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    NEATanks_time = glfwGetTime();

    return window;
}

void resizeDisplay(GLFWwindow* window, int width, int height) {
    glfwSetWindowSize(window, width, height);
    glViewport(0, 0, width, height);
}

bool shouldRender() {
    return 1.0 / FPS - (glfwGetTime() - NEATanks_time) <= 0;
}

void updateDisplay(GLFWwindow* window) {
    std::this_thread::sleep_for(std::chrono::milliseconds((int)((1.0/FPS - (glfwGetTime() - NEATanks_time))*1000)));
    NEATanks_time = glfwGetTime();
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void closeDisplay(GLFWwindow* window) {
    glfwDestroyWindow(window);
}