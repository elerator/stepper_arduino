#include "stepper.h"
#include <arduino.h>

Stepper::Stepper(int pin0, int pin1, int pin2, int pin3, int millis_per_step, long steps_left){
  if(steps_left < 0)this->run_forever = true;
  else this->run_forever = false;

  this->direction_reverse = false;
  this->pins[0] = pin0;
  this->pins[1] = pin1;
  this->pins[2] = pin2;
  this->pins[3] = pin3;
  this->reset(millis_per_step, steps_left);
};

void Stepper::reset(int millis_per_step, unsigned long steps_left){
  if(millis_per_step < 0){
    millis_per_step *= -1;
    this->direction_reverse = true; 
  };
  
  this->millis_per_step = millis_per_step;
  this->current_state = 0;
  this->steps_left = steps_left;

  unsigned long current_time = millis();
  t_next_step = current_time + millis_per_step;
}

void Stepper::step(unsigned long steps){
  this->steps_left = steps;
}

void Stepper::set_state(int state){
  //Serial.println(state);
  int* high_low = this->states[state];//curre
  for(int i = 0; i < pins_per_state; i++){
    digitalWrite(pins[i], high_low[i]);
  }
}

bool Stepper::update(){
  if(steps_left > 0 || run_forever){
    unsigned long current_time = millis();
    if(t_next_step <= current_time){
      t_next_step = t_next_step + millis_per_step;//If board is too slow, steps will be missed:
      //We schedule time for next step while already two should have been performed by then. Motor speed will be incorrect
      steps_left --;

      //Serial.println(steps_left);

      if(!direction_reverse){
        current_state ++;
      }else{
        current_state --;
      };
      
      if(current_state >= n_states)current_state = 0;
      if(current_state < 0)current_state = n_states-1;
      set_state(current_state);
    };
    
  }
}
