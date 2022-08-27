#include <stdio.h>
#include <stdlib.h>
#include "keyInput.h"
#include <GLFW/glfw3.h>


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (action == GLFW_PRESS) {
      keyPressed[key] = 1;
  } else if (action == GLFW_RELEASE) {
      keyPressed[key] = 0;
  }
}

int isKeyPressed(int keyCode) {
  return keyPressed[keyCode];
}

