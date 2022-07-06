#include <Arduino.h>
#include <Servo.h>

class Lock
{
public:
    virtual void open() = 0;
    virtual void close() = 0;

    virtual bool isOpened() = 0;
};

class ServoLock : public Lock
{
private:
    Servo servo;

    int openAngle;
    int closeAngle;

    bool opened = false;

public:
    ServoLock(int servoPin, int openAngle, int closeAngle);

    virtual void open() override;
    virtual void close() override;

    virtual bool isOpened() override;

};
