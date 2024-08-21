# Project Notes

## Main Goal with OpenGL ES
- [ ] Get stereoscopic demo up and going for Walter
    - Use Ian's code : https://gitlab.com/ianzur/bt40-linux-driver
- [ ] Learn how to display basic shape in `single` window
  - [ ] Repeat with two windows with a static shape
  - [ ] Repeat the same with a moving object to get a better understanding of how buffers work
- [ ] Learn how OpenGL ES deals with stereoscopic stuff

---

# Useful references 
- [Getting started with OpenGL ES](https://www.khronos.org/opengles/)
- [Getting Started with OpenGL ES 3+ Programming](https://keasigmadelta.com/store/wp-content/uploads/2017/03/GLES3-and-SDL2-Tutorials.pdf)
---

# Important Notes

## VideoCore VII GPU
- Only supports OpenGL ES 3.1
- Vulkan 1.2
- Mesa 3D Graphics library version 23.3

### When using GLFW
- Since the RPI5 only supports OpenGL ES 3.1 you `HAVE` to use the following
    ```cpp
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    ```

## How to resolve `lsERROR::SHADER::VERTEX::COMPILATION_FAILED 0:1(10): error: GLSL 3.30 is not supported. Supported versions are: 1.00 ES, 3.00 ES, and 3.10 ES`
- Possible solution
  - ~~["GLSL 3.30 is not supported" when compiling GLSL shader on Ubuntu 18.04?](https://stackoverflow.com/questions/52592309/glsl-3-30-is-not-supported-when-compiling-glsl-shader-on-ubuntu-18-04)~~
  - ~~Run the following command : `export MESA_GL_VERSION_OVERRIDE=3.3`~~
  - What is `Mesa`?
    - 3D graphics library
    - An open-sourced implementation of OpenGL/Vulkan and other graphics API applications
    - Mesa trasnlates the specifications per vendor-specific graphic hardware drivers
- Actual solution to shader issue
  - Need to change `From this`
    ```cpp
    const char *vertexShaderSource = "#version 330 core\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                    "}\0";
    const char *fragmentShaderSource = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                    "}\n\0";
    ```
    To `this`
    ```cpp
    const char *vertexShaderSource = "#version 310 es\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                    "}\0";

    const char *fragmentShaderSource = "#version 310 es\n"
                                    "precision mediump float;\n"
                                    "out vec4 FragColor;\n"
                                    "void main()\n"
                                    "{\n"
                                    "   FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
                                    "}\n\0";
    ```

---

# Tutorial Notes

## [Creating a window](https://learnopengl.com/Getting-started/Creating-a-window)

### First thing to learn : How to make a `application window` to draw in
- Such operations are OS specific 
- OpenGL tries to abstract itself from OS specific operations 
  - Meaning that we have to 
    - Create a window 
    - Define a context
    - Handle the user's input all by ourselves    
  - There are a ton of libraries that saves us from all the OS specific work and can give us a window and an OpenGL context to render in
    - But for the sake of learning from this website, we're sticking with `GLFW`

### GLFW
- Gives bare necessities needed to render stuff to a screen
- Big focus on this chapter 
  - Get GLFW up and running 
  - Make sure it's properly creates an OpenGL context and displaying a window that you can mess around with

### Install notes for GLFW
- Dependencies : `sudo apt install libwayland-dev libxkbcommon-dev xorg-dev`