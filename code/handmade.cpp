//------------------------------------------------------------------------------
/// Main entry point for the game
///

#include <GLFW/glfw3.h>

struct BitmapRGBA
{
    const static int BITS_PER_PIXEL = 4;
    int width;
    int height;
    GLubyte* data;
};
static BitmapRGBA bitmap;
static bool running;

static void error_callback(int error, const char* description)
{
    // fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        running = false;
    }
}

// static void window_size_callback(GLFWwindow* window, int width, int height)
// {
//     // int left, top, right, bottom;
//     // glfwGetWindowFrameSize(window, &left, &top, &right, &bottom);
// }

static void resize_bitmap(int width, int height)
{
    // Only allocate new space if needed
    int new_size = width * height * BitmapRGBA::BITS_PER_PIXEL;
    if (bitmap.data) {
        delete bitmap.data;
    }
    bitmap.data = new GLubyte[new_size];
    bitmap.width = width;
    bitmap.height = height;
}

static void update_window(GLFWwindow* window)
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2f(-1,1);
    glPixelZoom( 1, -1 );
    glDrawPixels(bitmap.width, bitmap.height, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.data);
    glfwSwapBuffers(window);
}

static void render_gradient(int xoff, int yoff)
{
    GLuint *pixel = (GLuint *)bitmap.data;
    for (int row = 0; row < bitmap.height; ++row) {
        for (int col = 0; col < bitmap.width; ++col) {
            *(pixel++) = (0xff << 24)
                | (((GLuint)col + xoff) << 16)
                | (((GLuint)row + yoff) << 8)
                | (0x0 << 0);
        }
    }
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    resize_bitmap(width, height);
    update_window(window);
}

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
    // glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);

    running = true;
    int xoff = 0;
    int yoff = 0;
    while (running)
    {
        render_gradient(xoff++, yoff);
        update_window(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    // return EXIT_SUCCESS;
}
