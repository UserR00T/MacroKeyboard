#include "Keyboard.h"

const byte numRows = 3;
const byte numCols = 5;
const byte rowPins[numRows] = { 0, 1, 2 };
const byte colPins[numCols] =  {  3, 4, 5, 6, 7 };
const char keymap[numRows][numCols] = {
  {203, 204, 205, 240, 241}, // F10  F11  F12  F13  F14
  {242, 243, 244, 245, 246}, // F15  F16  F17  F18  F19
  {247, 248, 249, 250, 251}  // F20  F21  F22  F23  F24
};
char pressed[numRows][numCols];

void setup() {
  // Reset rows and columns pin mode
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], INPUT);
  }
  for (int i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  // Initialize keyboard
  Keyboard.begin();
}

void loop() {
  for (int col = 0; col < numCols; col++) {
    // Fetch current column pin from array
    byte colPin = colPins[col];
    // Set output to low for current column
    pinMode(colPin, OUTPUT);
    digitalWrite(colPin, LOW);

    // Iterate through the rows
    for (int row = 0; row < numRows; row++) {
      // Fetch current row pin from array
      byte rowPin = rowPins[row];
      // Set mode to input_pullup and fetch value
      pinMode(rowPin, INPUT_PULLUP);

      // If row reading is low (aka off), fetch key from keymap and press it
      if (digitalRead(rowPin) == LOW) {
        pressed[row][col] = true;
        Keyboard.press(keymap[row][col]);
      }
      // If row reading is high and the key is/was pressed, release key
      else if (pressed[row][col]) {
        pressed[row][col] = false;
        Keyboard.release(keymap[row][col]);
      }

      // Reset mode to input
      pinMode(rowPin, INPUT);
    }
    // Reset column
    pinMode(colPin, INPUT);
  }
}
