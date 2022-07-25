#include <Keypad.h>

template <const byte Rows = 4, const byte Cols = 4> 
class NumPad
{
private:
  Keypad* keypad; 
 
  char keyMap [Rows] [Cols] = { 
  
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'}, 
  {'*', '0', '#', 'D'} 
  }; 
  
  byte rowPins [Rows] = {2, 3, 4, 5};
  byte colPins [Cols] = {6, 7, 8, 9}; 

public:

  void setMapping(char newKeyMap[Rows][Cols], byte newRowPins[Rows], byte newColPins[Cols])
  {
    delete keypad;
    keypad = new Keypad( makeKeymap(newKeyMap), newRowPins, newColPins, Rows, Cols);
  }

  NumPad()
  {
    keypad = new Keypad( makeKeymap(keyMap), rowPins, colPins, Rows, Cols);
  }

  ~NumPad()
  {
    delete keypad;
  }

  char getKey()
  {
    return keypad->getKey();
  }
};
