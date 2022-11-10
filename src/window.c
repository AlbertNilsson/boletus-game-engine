
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/keyInput.h"
#include "include/cursorInput.h"
#include "util/include/time.h"
#include "include/scene.h"

int i = 0, currentScene = 2;
double r, g, b, a;
double xPos, yPos, dt, startTime, endTime;

void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mods){
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}


int main(void) {
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
  while (!glfwWindowShouldClose(window)) {
    startTime = getWallSeconds();
    endTime = getWallSeconds();
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    if(isKeyPressed(GLFW_KEY_C))
      currentScene = 1;
    if(isKeyPressed(GLFW_KEY_SPACE)) { 
      glClearColor(r, g, b, a);
    } else {
      glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
      r = (double)rand()/RAND_MAX;
      g = (double)rand()/RAND_MAX;
      b = (double)rand()/RAND_MAX;
      a = (double)rand()/RAND_MAX;
    }
    updateScene(currentScene, dt);
    
      /* Swap front and back buffers */
    glfwSwapBuffers(window);

    endTime = getWallSeconds();
    dt = endTime-startTime;
    startTime=endTime;
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
