#include "intsmoothing.h"

IntSmoothing::IntSmoothing() {
  // Fill the array with zeroes
  for (int i = 0; i < smoothingFactor; i++) {
    history[i] = 0;
  }
}

int IntSmoothing::smooth(int inputValue) {
  total = total - history[historyIndex];  // Subtract the oldest value
  history[historyIndex] = inputValue;     // Add the new value to the array
  total = total + history[historyIndex];  // Add the new value to the total

  historyIndex++;                         // Advance the index
  if (historyIndex >= smoothingFactor) {  // Wrap around if needed
    historyIndex = 0;
  }

  return total / smoothingFactor;                      // Return the average
}
