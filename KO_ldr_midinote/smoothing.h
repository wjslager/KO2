// Based on the arduino value smoothing tutorial
// https://www.arduino.cc/en/Tutorial/Smoothing

const int smoothingFactor = 9;

class ValueSmoothing {
  public:
    ValueSmoothing();
    int smooth(int inputValue);
  private:
    int history[smoothingFactor];
    int historyIndex = 0;
    int total = 0;
};

