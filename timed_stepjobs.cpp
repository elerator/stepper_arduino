#include "timed_stepjobs.h"
#include <arduino.h>

TimedStepjob::TimedStepjob(int pin0, int pin1, int pin2, int pin3, int * state_durations, int* state_delays, int n_states){
  this->current_state = -1;
  this->n_states = n_states;
  this->state_delays = state_delays;
  this->state_durations = state_durations;
  this->stepper = new Stepper(pin0, pin1, pin2, pin3, 2, -1);
  this->next_time = millis();
  this->next_state();
}

void TimedStepjob::update(){
  if(millis() >= next_time)next_state();
  stepper->update();
}

void TimedStepjob::next_state(){

  current_state ++;
  if(current_state >= n_states)current_state = 0;
  Serial.println(state_delays[current_state]);

  stepper->reset(state_delays[current_state], -1);
  stepper->update();
  next_time = next_time+state_durations[current_state];
}
