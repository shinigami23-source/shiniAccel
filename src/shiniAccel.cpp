#include <shiniAccel.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

  TwoWire I2Ctwo = TwoWire(1);
   MPU6050 simpu(0x68, &I2Ctwo);
void shiniAccel::begin(){
   //  simpu(0x68, &I2Ctwo);

  I2Ctwo.begin(MPU_SDA, MPU_SCL);
 
delay(500);
    simpu.initialize();

    if (simpu.testConnection() == false) {
    #ifdef DEBUG
    Serial.println("MPU6050 connection failed");
    #endif
    while (true)

   
    #ifdef DEBUG
    Serial.println("MPU6050 connection successful");
    #endif
  }

//OFFSETS

  simpu.setXAccelOffset(GX_OFFSET);  //Set your accelerometer offset for axis X
  simpu.setYAccelOffset(GY_OFFSET);  //Set your accelerometer offset for axis Y
  simpu.setZAccelOffset(GZ_OFFSET);  //Set your accelerometer offset for axis Z
  simpu.setXGyroOffset(AX_OFFSET);     //Set your gyro offset for axis X
  simpu.setYGyroOffset(AY_OFFSET);     //Set your gyro offset for axis Y
  simpu.setZGyroOffset(AZ_OFFSET);    //Set your gyro offset for axis Z
}

void shiniAccel::read(){
    //read and store sensor data
  simpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  temp = (simpu.getTemperature() + 12421) / 340 ;

  if(temp != lastTemp){
    lastTemp = temp;
  }
   #ifdef DEBUG

   //print accel data
    Serial.print("ax:");
    Serial.print(ax);
    Serial.print(", ay:");
    Serial.print(ay);
    Serial.print(", az:");
    Serial.print(az);
//print gryo data
    Serial.print(", gx:");
    Serial.print(gx);
    Serial.print(", gy:");
    Serial.print(gy);
    Serial.print(", gz:");
    Serial.println(gz);

//print 
    Serial.print("temp:");
    Serial.println(temp);

    #endif


}