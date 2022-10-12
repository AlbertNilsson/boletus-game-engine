#include <stdio.h>
#include <stdlib.h>
#include "../headers/keyInput.h"

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (action == GLFW_PRESS) {
      keyPressed[key] = 1;
      printf("Key %d pressed\n", key);
  } else if (action == GLFW_RELEASE) {
      keyPressed[key] = 0;
      printf("Key %d released\n", key);
  }
}

int isKeyPressed(int keyCode) {
  return keyPressed[keyCode];
}

