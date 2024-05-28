#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

void display() {
    
}

int main(int argc, char** argv) {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("GLFW Initialization failed");
        glfwTerminate();
        return 1;
    }

    // Set up GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Core profiles = No backward compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test window", NULL, NULL);

    if (!mainWindow) {
        printf("Main window creation failed!");
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set context for GLEW
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("GLEW Initialize failed!");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
    }

    // Set up view port
    glViewport(0, 0, bufferWidth, bufferHeight);

    // Main for loop untill window closed
    while (!glfwWindowShouldClose(mainWindow)) {

        // Get + Handle user input
        glfwPollEvents();

        // Window clear colour
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(mainWindow);
    }

    return 0;
}