#define DEBUG 1  // Uncomment this line to enable debug
#include <shiniAccel.h>

#define MPU_SDA 32  //33
#define MPU_SCL 33  //32
#define OUTPUT_READABLE_ACCELGYRO
#define GX_OFFSET -0.013323
#define GY_OFFSET -0.114922
#define GZ_OFFSET 0.006662
#define AX_OFFSET 1.084573
#define AY_OFFSET -0.024248
#define AZ_OFFSET 10.56561

shiniAccel mpu;

void setup(){

#   ifdef DEBUG 
     Serial.begin(115200);  //begin
      delay(500);
    #endif

    compass.begin();
    delay(500);


    #ifdef DEBUG 
     Serial.print("mpu6050 started...");
    #endif


}

void loop(){
  mpu.read();


}
