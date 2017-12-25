#include <Arduino.h>
#include "sequencer.h"

Sequencer::Sequencer(float newTriggerLength)
{
  triggerCount = 0;
  triggerLength = newTriggerLength;
}

void Sequencer::setSpeed(float newTriggerLength)
{
  triggerLength = newTriggerLength;
}

void Sequencer::run(void triggerFunc())
{
  // Calculate the next time it should execute triggerFunc()
  nextTriggerTime = lastTriggerTime + triggerLength;

  if (millis() >= nextTriggerTime) {
    // Execute the function passed as argument
    triggerFunc();

    // Store the time it executed triggerFunc()
    lastTriggerTime = millis();
    triggerCount++;
  }
}

