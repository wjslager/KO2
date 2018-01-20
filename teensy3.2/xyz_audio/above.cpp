#include <Arduino.h>
#include "above.h"

Above::Above()
{
  millisAbove = 0;
}

boolean Above::checkAbove(float value, float threshold)
{
  if (value >= threshold) {
    millisAbove++;
    if (millisAbove == 1) {
      return true;
    }
  }
  else {
    millisAbove = 0;
  }
  
  return false;
}


