#include "keypad.hpp"

class PinModul
{
private:
  String pin;
  String currentPin;

  NumPad<> pad;

public:
  PinModul(String pin = "1234") : pin{pin}
  {
    //this->pin = "01";
    currentPin = "";
  }

  bool isSolved()
  {
    bool solved = pin == currentPin;
    //Serial.print(solved);
    return solved;
  }

  void handleInput()
  {
    char key = pad.getKey();
    switch(key)
    {
      case '#':
        currentPin = "";
        break;
      case '0':
        currentPin += key;
        break;
      case '1':
        currentPin += key;
        break;
      case '2':
        currentPin += key;
        break;
      case '3':
        currentPin += key;
        break;
      case '4':
        currentPin += key;
        break;
      case '5':
        currentPin += key;
        break;
      case '6':
        currentPin += key;
        break;
      case '7':
        currentPin += key;
        break;
      case '8':
        currentPin += key;
        break;
      case '9':
        currentPin += key;
        break;
      default:
        break;
    }
    
  }
};
