    void MPU_6050_setup(){

      Wire.begin();
      Wire.beginTransmission(MPU6050_addr);
      Wire.write(0x6B);
      Wire.write(0);
      Wire.endTransmission(true);
    }

    void MPU_6050_loop(){

      Wire.beginTransmission(MPU6050_addr);
      Wire.write(0x3B);
      Wire.endTransmission(false);
      Wire.requestFrom(MPU6050_addr,14,true);
      AccX=Wire.read()<<8|Wire.read();
      AccY=Wire.read()<<8|Wire.read();
      AccZ=Wire.read()<<8|Wire.read();
      Temp=Wire.read()<<8|Wire.read();
      GyroX=Wire.read()<<8|Wire.read();//+960;
      GyroY=Wire.read()<<8|Wire.read();//-30;
      GyroZ=Wire.read()<<8|Wire.read();//+448;


      //convert the values to degs/sec
      GyroX = (GyroX/131)+5.3;
      GyroY = (GyroY/131)-.2;
      GyroZ = (GyroZ/131)+1.5;

      //calculate the angle the accelerometer thinks you are at
      accpitch =  atan(AccY / sqrt(sq(AccX) + sq(AccZ))) * RadtoDeg;
      accpitch_f = .02* accpitch + .98 * accpitch_f;
      accroll = atan(AccX / sqrt(sq(AccY) + sq(AccZ))) * RadtoDeg;
      accroll_f = .02* accroll + .98 * accroll_f;

      //calulate the angle the gyro thinks you are at
      gyropitch = pitch + GyroX*dt;
      gyropitch_f = .02* gyropitch + .98 * gyropitch_f;
      gyroroll  = roll - GyroY*dt;
      gyroroll_f = .02* gyroroll + .98 * gyroroll_f;

      pitch = .98 * gyropitch + .02 * accpitch_f;
      roll =  .98 * gyroroll + .02 * accroll_f;

      pitch_f = .85* pitch + .15 * pitch_f;
      roll_f = .85* roll + .15 * roll_f;
    }
