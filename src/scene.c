#include "include/scene.h"
#include "include/keyInput.h"
#include <stdio.h>
#include <stdlib.h>


void updateLevel(int scene, double dt) {
    printf("inside level scene");
}

void updateEditor(double dt) {
}

void updateScene(int scene, double dt) { 
  switch(scene) {
    case 1: 
      updateLevel(dt, scene); // under dev
      break;
    case 2:
      updateEditor(dt);
      break;
    otherwise: {
      printf("%i is a undefined scene", scene);
      exit(-1);
               }
  }
} 



