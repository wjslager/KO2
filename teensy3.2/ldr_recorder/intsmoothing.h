// Based on the arduino value smoothing tutorial
// https://www.arduino.cc/en/Tutorial/Smoothing

const int smoothingFactor = 20;

class IntSmoothing {
  public:
    IntSmoothing();
    int smooth(int inputValue);
  private:
    int history[smoothingFactor];
    int historyIndex = 0;
    int total = 0;
};
