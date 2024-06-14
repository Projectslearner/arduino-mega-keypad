/*
    Project name : Keypad
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-keypad
*/

#include <Keypad.h>

const byte ROWS = 4; // Number of rows in the keypad
const byte COLS = 4; // Number of columns in the keypad

// Define the key mapping of the keypad (4x4 matrix)
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Define the keypad rows and columns
byte rowPins[ROWS] = {22, 24, 26, 28}; // Connect to the row pins of the keypad
byte colPins[COLS] = {30, 32, 34, 36}; // Connect to the column pins of the keypad

// Create an instance of Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read key press from keypad
  char key = keypad.getKey();

  // Check if a key is pressed
  if (key != NO_KEY) {
    Serial.println(key); // Print the pressed key to Serial Monitor
  }
  
  delay(100); // Small delay to debounce the keypad
}
