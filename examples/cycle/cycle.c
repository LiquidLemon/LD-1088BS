#include "../../lib.c"

int main() {
  init();
  int x, y;
  while (1) {
    for (x = 0; x < 8; ++x) {
      for (y = 0; y < 8; ++y) {
        setSingleLED(x, y);
        delay(100);
      }
    }    
  }
}
