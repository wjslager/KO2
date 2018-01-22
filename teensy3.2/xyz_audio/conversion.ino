#include <cmath>

// Convert midi notes to frequency in hz
float mtof(float midiNote)
{
  return pow(2, (midiNote - 69) / 12) * 440;
}

float clip(float in, float lower, float upper)
{
  return std::max(lower, std::min(in, upper));
}

