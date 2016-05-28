#include <stdlib.h>
#include <time.h>
#include "../../lib.c"

PI_THREAD (refresh_thread) {
  while (1) refresh();
}

int main() {
  init();
  srand(time(NULL));
  if (piThreadCreate(refresh_thread) != 0) return -1;
  int i;
  while (1) {
    for (i = 0; i < 8; ++i) {
      if (rand() % 10 > 4) {
        displayBuffer[0][i] = 1; 
      }      
    }
    delay(500);
    scrollDisplay(DIR_RIGHT, 0);
  }
  return 0;
}
