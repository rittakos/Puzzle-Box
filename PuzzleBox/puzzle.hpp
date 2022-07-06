#include "lock.hpp"
#include "button.hpp"
#include "led.hpp"

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

  const int servoPin = 9;
  const int buttonPin = 8;
  const int ledPin = LED_BUILTIN;
  
public:
  BasicPuzzle()
  {
    lock = new ServoLock(servoPin, 90, 0);
    button = new Button(buttonPin);
    led = new Led(ledPin);
    led->off();
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
    if(button->isPressed())
    {
      if(state == DONE)
      {
        reset();
      }else
      {
        state = DONE;
      }
      delay(200);
    }
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
    if(state == DONE)
    {
      lock->open();
      led->on();
    }
  }
};
