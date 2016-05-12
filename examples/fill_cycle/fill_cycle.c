#include <stdio.h>
#include "../../lib.c"

PI_THREAD (refresh_thread) {
  while (1) {
    refresh();
  }
}

int main() {
  init(); 
  if(piThreadCreate(refresh_thread) != 0) {
    puts("Couldn't create refresh thread");
    return -1;
  }
  while (1) {
    int x, y;
    for (x = 0; x < 8; ++x) {
      for (y = 0; y < 8; ++y) {
        invertLED(x, y);
        delay(100);
      }
    }
  }
}
