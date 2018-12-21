
      const int MPU6050_addr=0x68;

      //Global Variables
      float AccX, AccY, AccZ, Temp, GyroX, GyroY, GyroZ;
      float accpitch, accroll, gyropitch, gyroroll;
      float pitch, roll, pitch_error, roll_error;
      float pitch_command, roll_command;
      float dt;
      float RadtoDeg = 180 / 3.1415;
      float throttle_input, pitch_input, roll_input, mode_input;

      //Pin Setup Params
      int ch1_pin = 4; //Throttle input pin (Digital)
      int ch2_pin = 5; //Aileron input pin (Digital)
      int ch3_pin = 6; //Elevator input pin (Digital)
      int ch4_pin = 12; //Mode input pin (Digital)

      int pitch_servo_pin = 8; //Pitch servo pin (Digital)
      int roll_servo1_pin = 9; //Roll servo1 pin (Digital)
      int roll_servo2_pin = 10; //Roll servo2 pin (Digital)

      //Pitch Axis Configuration
      Servo pitch_servo;

      float pitch_pidsum;
      float pitch_servo_angle;

      //Pitch Axis Params
      int pitch_servo_center = 90; //Adjust this value to trim the aircraft
      float p_pitch = .9; float P_pitch;
      float i_pitch = 0; float I_pitch_old; float I_pitch_new;
      float d_pitch = 0; float D_pitch;

      //Roll Axis Configuration
      Servo roll_servo1;
      Servo roll_servo2;
      float roll_pidsum;
      float roll_servo_angle;
      float roll_servo2_angle;

      //Roll Axis Params
      int roll_servo_center = 90; //Adjust this value to trim the aircraft
      float p_roll = 1.5; float P_roll;
      float i_roll = 0; float I_roll_old; float I_roll_new;
      float d_roll = 0; float D_roll;


      int counter = 0;


      unsigned long int a,b,c;
      int x[15],ch1[15],ch[7],i;
      //specifing arrays and variables to store values


      int mode = 1; //mode 1 - stabilize, mode 2 - acro , mode 3 - manual
      int mode_input_prev;


      float roll_f = 0;
      float pitch_f = 0;
      float accpitch_f = 0;
      float accroll_f = 0;
      float gyropitch_f = 0;
      float gyroroll_f = 0;
