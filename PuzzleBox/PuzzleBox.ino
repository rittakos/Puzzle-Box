#include <Arduino.h>

#include "puzzle.hpp"

Puzzle* puzzle;

void setup() {
  puzzle = new BasicPuzzle();
}

// the loop function runs over and over again forever
void loop() {
  handleInput();
  puzzle->update(); 
}

void handleInput()
{
  puzzle->handleInputs();
}
