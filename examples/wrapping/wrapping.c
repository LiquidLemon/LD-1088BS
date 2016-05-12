#include "../../lib.c"

char map[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

PI_THREAD (refresh_thread) {
  while (1) refresh();
}

int main() {
  init();
  setMap(map);
  invertDisplay();
  if (piThreadCreate(refresh_thread) != 0) return -1;
  while (1) {
    delay(1000);
    scrollDisplay();
  }
}
