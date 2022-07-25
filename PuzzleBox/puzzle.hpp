#include "lock.hpp"
#include "button.hpp"
#include "led.hpp"
#include "pinModul.hpp"

class Puzzle
{
public:
  virtual void handleInputs() = 0;  
  virtual void reset() = 0;
  virtual bool isSolved() const = 0;
  virtual void update() = 0;
};

class BasicPuzzle final : public Puzzle
{
private:
  enum State{INITED, INPROGRESS, DONE};

  State state;
  Lock* lock;
  Button* button;
  Led* led;
  PinModul* pinModul;

  const int servoPin = 9;
  const int buttonPin = 8;
  const int ledPin = LED_BUILTIN;
  
public:
  BasicPuzzle()
  {
    Serial.begin(9600);
    lock = new ServoLock(servoPin, 90, 0);
    button = new Button(buttonPin);
    led = new Led(ledPin);
    led->off();
    pinModul = new PinModul("3210");
    state = State::INITED;
  }

  ~BasicPuzzle()
  {
    delete lock;
    delete button;
    delete led;
  }

  virtual void handleInputs() override
  {
    pinModul->handleInput();
    /*if(button->isPressed())
    {
      if(state == DONE)
      {
        reset();
      }else
      {
        state = DONE;
      }
      delay(200);
    }*/
  }
  
  virtual void reset() override
  {
    state = State::INITED;
    lock->close();
    led->off();
  }
  
  virtual bool isSolved() const override
  {
    return state == DONE;
  }

  virtual void update() override
  {
    if(pinModul->isSolved())
      state = DONE;
    else
      state = INPROGRESS;
    if(state == DONE)
    {
      lock->open();
      led->on();
      Serial.print("Done");
    }
  }
};
