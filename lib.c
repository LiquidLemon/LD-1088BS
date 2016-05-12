#include <wiringPi.h>

const int rows[] = {8, 9, 7, 15, 16, 0, 2, 3};
const int columns[] = {4, 5, 12, 13, 6, 14, 10, 11};

int displayMap[8][8] = {
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 0, 1}
};

void refresh() {
  int x, y;
  for (x = 0; x < 8; ++x) {
    digitalWrite(columns[x], LOW);
    for (y = 0; y < 8; ++y) {
      if (displayMap[x][y]) {
        digitalWrite(rows[y], HIGH);
        digitalWrite(rows[y], LOW);
      }  
    }
    digitalWrite(columns[x], HIGH);
  }
}

void setSingleLED(int x, int y) {
  int i;
  for (i = 0; i < 8; ++i) {
    if (i == x)
      digitalWrite(columns[i], LOW);
    else
      digitalWrite(columns[i], HIGH);

    if (i == y)
      digitalWrite(rows[i], HIGH);
    else
      digitalWrite(rows[i], LOW);
  }
}

void clear() {
  int i;
  for (i = 0; i < 8; ++i) {
    digitalWrite(columns[i], HIGH);
    digitalWrite(rows[i], LOW);
  }
}

void fill() {
  int i;
  for (i = 0; i < 8; ++i) {
    digitalWrite(columns[i], LOW);
    digitalWrite(rows[i], HIGH);
  }
}

void init() {
  wiringPiSetup();
  int i;
  for (i = 0; i < 8; ++i) {
    pinMode(rows[i], OUTPUT);
    pinMode(columns[i], OUTPUT);

    digitalWrite(columns[i], HIGH);
  }
}
