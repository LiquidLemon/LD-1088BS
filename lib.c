#include <wiringPi.h>

const char rows[] = {8, 9, 7, 15, 16, 0, 2, 3};
const char columns[] = {4, 5, 12, 13, 6, 14, 10, 11};

char displayBuffer[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

// Broken, I'm not sure I need this so I'm just gonna leave it here
//
// char displayMap[8][8];
//
// void swapBuffer() {
//   int tmp[8][8];
//   tmp = displayBuffer;
//   displayBuffer = displayMap;
//   displayMap = tmp;
//   
//   int x, y;
//   for (x = 0; x < 8; ++x) {
//     for (y = 0; y < 8; ++y) {
//       displayMap[x][y] = displayBuffer[x][y];
//     }
//   }
// }

void setMap(char map[8][8]) {
  int x, y;
  for (x = 0; x < 8; ++x) {
    for (y = 0; y < 8; ++y) {
      displayBuffer[x][y] = map[x][y];
    }
  }
} 

// Displays the contents of displayBuffer
// Has to be calle continously to work
void refresh() {
  int x, y;
  for (x = 0; x < 8; ++x) {
    digitalWrite(columns[x], LOW);
    for (y = 0; y < 8; ++y) {
      if (displayBuffer[x][y]) {
        digitalWrite(rows[y], HIGH);
        digitalWrite(rows[y], LOW);
      }  
    }
    digitalWrite(columns[x], HIGH);
  }
}

void changeLED(int x, int y, int state) {
  displayBuffer[x][y] = state;
}

void setLED(int x, int y) {
  changeLED(x, y, 1);
}

void clearLED(int x, int y) {
  changeLED(x, y, 0);
}

void invertLED(int x, int y) {
  if (displayBuffer[x][y])
    displayBuffer[x][y] = 0;
  else
    displayBuffer[x][y] = 1;
}

void invertDisplay() {
  int x, y;
  for (x = 0; x < 8; ++x) {
    for (y = 0; y < 8; ++y) {
      invertLED(x, y);
    }
  }
}

void scrollDisplay() {
  int i, j;
  char tmp[8];
  for (i = 0; i < 8; ++i) {
    tmp[i] = displayBuffer[7][i];
  }
  
  for (i = 7; i > 0; --i) {
    for (j = 0; j < 8; ++j) {
      displayBuffer[i][j] = displayBuffer[i-1][j];
    }  
  }

  for (i = 0; i < 8; ++i) {
    displayBuffer[0][i] = tmp[i];
  }
}

// The following functions modify the display directly
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
    
    // Clear the display
    digitalWrite(columns[i], HIGH);
  }
}
