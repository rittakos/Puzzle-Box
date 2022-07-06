class Button final
{
private:
  const int pin;
   
public:
  Button(int pin) : pin{pin}
  {
    pinMode(pin, INPUT);
  }

  bool isPressed() const
  {
    return digitalRead(pin) == HIGH;
  }
};
