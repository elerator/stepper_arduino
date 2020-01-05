#ifndef Stepper_H
#define Stepper_H

class Stepper{
  private:
     bool run_forever;
     bool direction_reverse;//Flag for running stepper motor in opposite direction
     unsigned long steps_left;
     unsigned long t_next_step;
     unsigned long millis_per_step;
     
     int pins[4];
     
     int current_state;
     int n_states = 4;
     int pins_per_state = 4;
     int states[4][4] = {{0,0,1,1},
                         {1,0,0,1},
                         {1,1,0,0},
                         {0,1,1,0}};
  public:
     Stepper(int pin0, int pin1, int pin2, int pin3, int millis_per_step, long steps_left);
     void reset(int millis_per_step, unsigned long steps_left);
     void step(unsigned long steps);
     void set_state(int state);
     bool update();
};

#endif
