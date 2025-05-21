#define DEBUG 1  // Uncomment this line to enable debug
#include <shiniAccel.h>

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
