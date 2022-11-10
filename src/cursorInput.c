#include "include/cursorInput.h"
#include <stdio.h>
#include <stdbool.h>
double xPos = 0.0, yPos = 0.0, lastY = 0.0, lastX = 0.0, scrollX = 0.0, scrollY = 0.0;

int mouseButtonPressed[3] = {0,0,0};
bool isDragging;



void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
  lastX = xPos;
  lastY = yPos;
  xPos = xpos;
  yPos = ypos;
  isDragging = mouseButtonPressed[0] || mouseButtonPressed[1] || mouseButtonPressed[2];
  printf("xPos: %lf, yPos: %lf\n",xPos,yPos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
  if(button > 2) {
    printf("Boletus currently only support three mousebuttons");
  } else if (action == GLFW_PRESS){
    mouseButtonPressed[button] = 1;
    printf("button %d was pressed\n", button);
  } else if(action == GLFW_RELEASE) {
    isDragging = false;
    mouseButtonPressed[button] = 0;
    printf("button %d was released\n", button);
  }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
  scrollX = xoffset;
  scrollY = yoffset;
  printf("scrolling ... (%lf, %lf)\n", scrollX, scrollY);
}

void endFrame() {
  scrollX = 0;
  scrollY = 0;
  lastX = xPos;
  lastY = yPos;
}


