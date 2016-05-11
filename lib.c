#include <wiringPi.h>

const int rows[] = {8, 9, 7, 15, 16, 0, 2, 3};
const int columns[] = {4, 5, 12, 13, 6, 14, 10, 11};

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
