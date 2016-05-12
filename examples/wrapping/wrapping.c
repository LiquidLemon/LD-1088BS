#include "../../lib.c"

char map[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 1, 1, 0, 1, 0},
  {0, 1, 0, 1, 1, 0, 1, 0},
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
  //invertDisplay();
  if (piThreadCreate(refresh_thread) != 0) return -1;
  int i;
  int dir = 0;
  while (1) {
    for (i = 0; i < 8; ++i) {
      delay(250);
      scrollDisplay(dir, 1);
    }
    if (dir < 3)
      dir += 1;
    else
      dir = 0;
  }
}
