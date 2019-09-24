#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>
#include <Servo.h>

double distance;  //设置距离变量
Servo servo_6;  //实例化舵机库
WMUltrasonic Ultrasonic_3(3); //将3号口设置为超声波接口
WMDigitalTube DigitalTube_5(5); //将5号口设置为数码管接口
WMServo wmServo_2(2); //将2号口设置为二次开发接口

void setup(){
    servo_6.attach(6,0);  //将6号口设置为舵机接口
    delay(1000);  
}

void loop(){   
    servo_6.write(45);  //6号口舵机转到45度的位置
    delay(1000);
    distance = Ultrasonic_3.Distance(); //获取超声波检测到的距离
    DigitalTube_5.setDisplay(0,distance); //数码管显示距离
    if((distance) < (20)){   //如果该距离小于20cm
        wmServo_2.runActionGroup(11,1); //运行11号动作组一次
        while(!(wmServo_2.getRunOverCmd()));
    }
    servo_6.write(90);
    delay(1000);
    distance = Ultrasonic_3.Distance();
    DigitalTube_5.setDisplay(0,distance);
    if((distance) < (20)){
        wmServo_2.runActionGroup(12,1);
        while(!(wmServo_2.getRunOverCmd()));
    }
    servo_6.write(135);
    delay(1000);
    distance = Ultrasonic_3.Distance();
    DigitalTube_5.setDisplay(0,distance);
    if((distance) < (20)){
        wmServo_2.runActionGroup(13,1);
        while(!(wmServo_2.getRunOverCmd()));
    }    
}

