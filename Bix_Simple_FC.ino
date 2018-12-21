 #include "I2Cdev.h"
 #include "MPU6050.h"
 #include "Wire.h"
 #include "math.h"
 #include "Servo.h"
 #include "Config.h"
 
void setup() {
  rc_read_setup_ppm();
  MPU_6050_setup();
  servo_setup();
  delay(3000);
}

void loop() {
 
  
      int32_t StartTime = micros(); //start the timer to calculate looptime

  find_mode();
  serial_recorder();
  MPU_6050_loop();
  servo_loop();
  rc_read_ppm();
  
  if (mode == 1){
     horizon_mode();
  }
  else if (mode == 2){
    manual_mode();
    I_pitch_new = 0;
    I_roll_new = 0;
    I_pitch_old = 0;
    I_roll_old =0;
  }

  else {
    manual_mode();
    I_pitch_new = 0;
    I_roll_new = 0;
    I_pitch_old = 0;
    I_roll_old =0;
  }
 
  delay(10);
  
      //determine the dt for gyro calculation
      int32_t EndTime = micros();
      dt = (EndTime - StartTime); //calculate the time between gyro reading values for the complemenatary filter
      dt = (dt) / 1000000; //convert to seconds
}
