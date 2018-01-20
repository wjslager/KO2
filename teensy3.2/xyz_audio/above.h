#ifndef _ABOVE_H_
#define _ABOVE_H_

class Above
{
  public:
    Above();
    boolean checkAbove(float value, float threshold);
  private:
    float lastValue;
    int millisAbove;
};

#endif
