class FloatSmoothing {
  public:
    FloatSmoothing(float easing);
    float smooth(float inputValue);
  protected:
    float easing;
  private:
    float outputValue;
};
