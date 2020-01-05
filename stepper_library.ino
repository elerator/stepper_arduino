#include "stepper.h"
#include "timed_stepjobs.h"

//Stepper stepper = Stepper(10,11,12,13, 500, -1);
const int n_states = 4;
int state_delays [n_states] = {100,10,50,2};
int state_durations [n_states] = {2000,2000,2000,2000};
TimedStepjob stepjob1 = TimedStepjob(10,11,12,13, state_durations, state_delays, n_states);

void setup(){
    Serial.begin(9600);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop() {
  //stepper.update();
  stepjob1.update();
}
