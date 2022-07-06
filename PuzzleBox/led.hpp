class Led final
{
private:
  const int pin;
  bool lighting;
  
public:
  Led(int pin) : pin{pin}
  {
    pinMode(pin, OUTPUT);
    lighting = true;
    off();
  }

  void on()
  {
    if(lighting)
      return;
      
    lighting = true;
    digitalWrite(LED_BUILTIN, HIGH);
  }

  void off()
  {
    if(!lighting)
      return;
      
    lighting = false;
    digitalWrite(LED_BUILTIN, LOW);
  }
};
