

#ifndef shiniAccel_h
#define shiniAccel_h
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <shiniConfig.h>
 

   
class shiniAccel{
    private:

    /* MPU6050 default I2C address is 0x68*/

    int16_t ax, ay, az;
    int16_t gx, gy, gz;
    int8_t temp,lastTemp;

    public:
    void begin();
    void read();


};



#endif
