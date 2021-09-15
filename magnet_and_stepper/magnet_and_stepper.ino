#include <ros.h>
#include <std_msgs/UInt16.h>
#include <Grove_I2C_Motor_Driver.h>
// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f

ros::NodeHandle  nh;

void messageCb(const std_msgs::UInt16& msg){
  if(msg.data == 1){
    digitalWrite(LED_BUILTIN,HIGH);
    digitalWrite(6,HIGH);
  }else if (msg.data == 2){
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(6,LOW);
  }else if (msg.data == 3){
    Motor.StepperRun(-200,1,1);
  }else if (msg.data == 4){
    Motor.StepperRun(200,1,0);
  }
}

ros::Subscriber<std_msgs::UInt16> sub("magnettrigger", &messageCb );

void setup() {
    Serial.begin(9600);
    Motor.begin(I2C_ADDRESS);
    pinMode(LED_BUILTIN,OUTPUT);//for debug
    pinMode(6,OUTPUT);
    nh.initNode();
    nh.subscribe(sub);
/*  Motor.StepperRun() 第一引数：ステップ量（-1024~1024）・第二引数：Phase数（0:4phase/1:2phase）*/
}


void loop() {
  nh.spinOnce();
      digitalWrite(6,HIGH);
    delay(1000);

  delay(1);
}
