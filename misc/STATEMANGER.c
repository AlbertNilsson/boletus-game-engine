#include "STATEMANAGER.h"
#include <stdlib.h>
int STATEMANAGER_init(StateManager *statemanager) {
  statemanager -> capacity = 3;
  statemanager -> stack = malloc(statemanager -> capacity * sizeof(State*));
  statemanager -> top = -1;
  return 0;
};



int STATEMANAGER_free(StateManager *statemanager) {
  do {
    STATEMANAGER_pop(statemanager);
  } while (statemanager -> top > -1);
  free(statemanager -> stack);
  return 0;
}

int STATEMANAGER_pop(StateManager *statemanager) {
  if(statemanager ->top == -1) return 0;
  State *top = STATEMANAGER_top(statemanager);
  if(top ->destroy != NULL) top -> destroy();
  statemanager -> stack[statemanager -> top] = NULL;
  statemanager -> top --;
  return statemanager -> top;
  


  return 0;
}
State *STATEMANAGER_top(StateManager *statemanager) {
  return statemanager -> stack[statemanager -> top];
}
  
  
