
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/keyInput.h"
#include "../headers/cursorInput.h"



// gcc -o myprog window.c keyInput.c -lglfw -framework Cocoa -framework OpenGL -framework IOKit
int i = 0;
double r, g, b, a;
double xPos, yPos;

void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Boletus", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
      glfwMakeContextCurrent(window);

      glfwSetKeyCallback(window, key_callback);
//      glfwSetCursorPosCallback(window, cursor_position_callback);
      glfwSetCursorPosCallback(window, cursor_position_callback);

      glfwSetMouseButtonCallback(window, mouse_button_callback);
      glfwSetScrollCallback(window, scroll_callback);
    /* Loop until the user closes the window */
    r = (double)rand()/RAND_MAX;
    g = (double)rand()/RAND_MAX;
    b = (double)rand()/RAND_MAX;
    a = (double)rand()/RAND_MAX;
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        if(isKeyPressed(GLFW_KEY_SPACE)) { 
          glClearColor(r, g, b, a);
        } else {
          glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
          r = (double)rand()/RAND_MAX;
          g = (double)rand()/RAND_MAX;
          b = (double)rand()/RAND_MAX;
          a = (double)rand()/RAND_MAX;

        }
        /* Swap front and back buffers */
        glfwSwapBuffers(window);


        //glfwSetKeyCallback(window, key_callback);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
