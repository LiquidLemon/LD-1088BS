#include <stdio.h>
#include "../../lib.c"

char checkers[8][8] = {
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1}
};

PI_THREAD (refresh_loop) {
  while(1) { refresh(); }
}

int main() {
  init();
  setMap(checkers);
  if (piThreadCreate(refresh_loop) != 0) {
    puts("Thread didn't start");
    return -1;
  }
  while (1) {}
}
