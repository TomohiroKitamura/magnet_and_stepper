#include <Grove_I2C_Motor_Driver.h>

#define I2C_ADDRESS 0x0f

void setup() {
    pinMode(6,OUTPUT);
    digitalWrite(6,HIGH);
    Serial.begin(9600);
    Motor.begin(I2C_ADDRESS);
    delay(1000);
    Motor.StepperRun(-500,1,1);
    delay(1000);
    Motor.StepperRun(500,1,1);
}



void loop() {

    digitalWrite(6,HIGH);
}
