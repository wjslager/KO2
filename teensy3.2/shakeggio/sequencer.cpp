#include <Arduino.h>
#include "sequencer.h"

Sequencer::Sequencer(float newTriggerLength)
{
  triggerCount = 0;
  this->setTriggerLength(newTriggerLength);
}

boolean Sequencer::checkTrigger()
{
  // Returns true if it is time for the next trigger
  // Allows you to execute a block of code at each trigger
  nextTriggerTime = lastTriggerTime + triggerLength;

  if (millis() >= nextTriggerTime) {
    lastTriggerTime = millis();
    triggerCount++;
    return true;
  }
  else {
    return false;
  }
}

void Sequencer::setTriggerLength(float newTriggerLength)
{
  triggerLength = newTriggerLength;
}
