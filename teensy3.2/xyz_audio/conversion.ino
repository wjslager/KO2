#include <cmath>

// Convert midi notes to frequency in hz
float mtof(float midiNote)
{
  return pow(2, (midiNote - 69) / 12) * 440;
}
