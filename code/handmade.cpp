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

static void window_size_callback(GLFWwindow* window, int width, int height)
{
    // int left, top, right, bottom;
    // glfwGetWindowFrameSize(window, &left, &top, &right, &bottom);
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // glViewport(0, 0, width, height);
    // CreateDIBSecion (device independent bitmat)
}

static void resize_DIB_section(int width, int height)
{
    // Create fbo

}

// static void update_window(context, int x, int y, int width, int height)
// {
//     // TODO(ajc): use glCopyImageSubData in the future (in place of blit)

//     // Note GL_FRAMEBUFFER binds to both READ/DRAW
//     glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo);
//     glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
//     glBlitFramebuffer(
//         0, 0, width, height,             // src rect
//         0, 0, width, height,             // dst rect
//         GL_COLOR_BUFFER_BIT,             // buffer mask
//         GL_LINEAR);
// }

// TODO(ajc): error handling
int main(int argc, char const *argv[])
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        // return EXIT_FAILURE
    }

    // TODO(ajc): OpenGL version
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
    // TODO(ajc): Do I need both of these? Probably just framebuffer.
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



const unsigned int w = 640;
const unsigned int h = 480;
GLubyte pixels[w * h * 3];
for (unsigned int i = 0; i < w * h * 3; i+=3) {
    pixels[i + 0] = 0xff; // Red
    pixels[i + 1] = 0x0; // Green
    pixels[i + 2] = 0x0; // Blue
}
while (!glfwWindowShouldClose(window))
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(w, h, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glfwSwapBuffers(window);
    glfwPollEvents();
}


    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    // return EXIT_SUCCESS;
}
