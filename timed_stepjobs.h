#ifndef timed_stepjobs
#define timed_stepjobs

#include "stepper.h"
class TimedStepjob{
  private:
    Stepper* stepper;
    int n_states;
    int* state_durations;
    int* state_delays;

    int current_state;
    unsigned long next_time;
  public:
    TimedStepjob(int pin0, int pin1, int pin2, int pin3, int* state_durations, int* state_delays, int n_states);
    void update();
    void next_state();
};
#endif
