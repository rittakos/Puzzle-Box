#include <Arduino.h>
#include <Servo.h>

#include "puzzle.hpp"

Puzzle* puzzle;

void setup() {
  puzzle = new BasicPuzzle();
}

// the loop function runs over and over again forever
void loop() {
  handleInput();
}

void handleInput()
{
  puzzle->handleInputs();
}
