#ifndef _SEQUENCER_H_
#define _SEQUENCER_H_

class Sequencer
{
  public:
    Sequencer(float newTriggerLength);
    boolean checkTrigger();
    void setTriggerLength(float newTriggerLength);
    int triggerCount;
  private:
    float lastTriggerTime;
    float nextTriggerTime;
    float triggerLength;
};

#endif
