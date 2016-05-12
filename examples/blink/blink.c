#include "../../lib.c"

int main() {
  init();
  while (1) {
    fill();
    delay(750);
    clear();
    delay(750);
  }
}
