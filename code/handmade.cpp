//------------------------------------------------------------------------------
/// Main entry point for the game
///

#include <GLFW/glfw3.h>


static void error_callback(int error, const char* description)
{
    // fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// TODO(ajc): error handling
int main(int argc, char const *argv[])
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        // return EXIT_FAILURE
    }

    // TODO(ajc): OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // TODO(ajc): NO_API??

    // TODO(ajc): Window default size
    GLFWwindow* window = glfwCreateWindow(640, 480, "Handmade Hero", NULL, NULL);
    if (!window) {
        // Window or OpenGL context creation failed
        glfwTerminate();
        // return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        // Keep running
    }


    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    // return EXIT_SUCCESS;
}
