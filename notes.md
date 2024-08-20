# [Creating a window](https://learnopengl.com/Getting-started/Creating-a-window)

## First thing to learn : How to make a `application window` to draw in
- Such operations are OS specific 
- OpenGL tries to abstract itself from OS specific operations 
  - Meaning that we have to 
    - Create a window 
    - Define a context
    - Handle the user's input all by ourselves    
  - There are a ton of libraries that saves us from all the OS specific work and can give us a window and an OpenGL context to render in
    - But for the sake of learning from this website, we're sticking with `GLFW`

## GLFW
- Gives bare necessities needed to render stuff to a screen
- Big focus on this chapter 
  - Get GLFW up and running 
  - Make sure it's properly creates an OpenGL context and displaying a window that you can mess around with

## Install notes for GLFW
- Dependencies : `sudo apt install libwayland-dev libxkbcommon-dev xorg-dev`