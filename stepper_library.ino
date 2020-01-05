#include "stepper.h"
#include "timed_stepjobs.h"

//Stepper stepper = Stepper(10,11,12,13, 500, -1);
const int n_states = 4;
int state_delays [n_states] = {500,10,-550,2};
int state_durations [n_states] = {5000,2000,5000,2000};
TimedStepjob stepjob1 = TimedStepjob(0,1,2,3, state_durations, state_delays, n_states);

void setup(){
    Serial.begin(9600);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
}

void loop() {
  //stepper.update();
  stepjob1.update();
}
