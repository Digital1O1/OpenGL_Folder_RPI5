#include <glad/glad.h> // Glad MUST be included first, refer to documentation for details : https://learnopengl.com/Getting-started/Hello-Window
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 640;
const unsigned int SCR_HEIGHT = 480;

int main()
{
    // glfw: initialize and configure GLFW
    // ------------------------------
    glfwInit();

    // First argument tells us what option we want to configure by selecting any of the supported enums that are prefixed with GLFW_
    // The second argument is a integer that sets the value of our option
    // List of options can be found here : https://www.glfw.org/docs/latest/window.html#window_hints

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Don't use this on the RPI5

    // glfw window creation
    // --------------------
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Moves the actual screen
    glfwSetWindowPos(window, 300, 100);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD must be initialized before calling ANY OpenGL functions
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // render loop is where we want to place all the rendering commands
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);
        /*
            Notes about glfwSwapBuffers(window);
                - Syntax : void glfwSwapBuffers	(GLFWwindow * window)
                - Function swpas out both front/back buffers of the specirfied window
                - If the swap interval is GREATER THAN 0
                    - GPU waits for specifried number of screen updates BEFORE swapping buffers

            Notes about Double buffer(s)
                - If application draws in a single buffer, you could see display flickering issues
                - The flickering is due to the resulting output image not being drawn in an instant
                    - But by pixel by pixel
                    - Going from
                        - Left to Right
                        - Top to Bottom
                - Since the image isn't displayed in an instant to the user, the resulting image could have artifacts
                - To prevent this
                    - Windowing applications should apply a double buffer for rendering
                    - The FRONT buffer has the final output image that's shown to the screen
                    - The BACK buffer has all the rendering commands to draw
                    - As soon as the rendering commands are complete
                        - swap the back buffer to the front so the images can be displayed w/o being rendered to
        */

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    /*
        Notes about glfwGetKey()
            - What does it do : takes window as input together with any key presses
            - If statement checks if ESC key is pressed
                - If NOT pressed, glfwGetKey returns GLFW_RELEASE
                - If ESC is pressed
                    - WindowShouldClose() is set to TRUE using glfwSetWindowShouldClose()
    */
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // glViewport() is used to just RENDER stuff into the viewport window that was created in this example
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}