#include "floatsmoothing.h"

FloatSmoothing::FloatSmoothing(float easing)
{
  this->easing = easing;
}

float FloatSmoothing::smooth(float inputValue)
{
  if (outputValue != inputValue)
  {
    outputValue += (inputValue - outputValue) * easing;
    return outputValue;
  }
}

/*
  class Easing
  {
  float target, distance, output, easing;

  Easing(float easing)
  {
    this.easing = easing;
  }

  float ease(float input)
  {
    if (output != input) {
      target = input;
      distance = target - output;
      output += distance * easing;
      return output;
    }
    return input;
  }

  void setEase(float easing) {
    this.easing = easing;
  }
  }
*/
