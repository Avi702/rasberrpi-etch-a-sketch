#include <stddef.h>
#include <stdio.h>
#include "sense.h"
#include "sketch.h"
#include <math.h>
pi_i2c_t* i2c_device = NULL; pi_joystick_t* joystick = NULL;
void open_input(){
   if(i2c_device == NULL){
      i2c_device = geti2cDevice();
      if(i2c_device != NULL){
         configureAccelGyro(i2c_device);
      }
   }
   if(joystick == NULL){
      joystick = getJoystickDevice();
  }
}
void check_joy(void (*callback)(unsigned int), int delay) {
    if (joystick != NULL) {
        pollJoystick(joystick, callback, delay);
    }
}
int check_shake() {
    coordinate_t data;
    if(i2c_device == NULL) return 0;
    getAccelData(i2c_device, &data);
    double total = sqrt(pow(data.x,2) + pow(data.y,2) + pow(data.z,2));
    if (total > 1.5){
        return 1;
    }
    return 0;
}
void close_input() {
  if(i2c_device != NULL){
     freei2cDevice(i2c_device);
     i2c_device = NULL;
  }
  if(joystick != NULL){
     freeJoystick(joystick);
     joystick = NULL;
  }
}
