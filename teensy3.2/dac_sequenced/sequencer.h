#ifndef _SEQUENCER_H_
#define _SEQUENCER_H_

class Sequencer
{
  public:
    Sequencer(float newTriggerLength);
    void run(void triggerFunc());
    void setSpeed(float newTriggerLength);
  private:
    float lastTriggerTime;
    float nextTriggerTime;
    float triggerLength;
    int triggerCount;
};

#endif
