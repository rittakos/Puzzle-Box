#include "lock.hpp"
#include <Servo.h>

ServoLock::ServoLock(int servoPin, int openAngle, int closeAngle) : openAngle(openAngle), closeAngle(closeAngle)
{
  servo.attach(servoPin);
  opened = true;
  close();
}

void ServoLock::open()
{
  if(opened)
    return;
	opened = true;
  servo.write(openAngle);
}


void ServoLock::close()
{
  if(!opened)
    return;
	opened = false;
  servo.write(closeAngle);
}

bool ServoLock::isOpened()
{
  return opened;
}
