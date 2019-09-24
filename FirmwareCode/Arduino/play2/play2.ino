#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

double distance;  //设置距离变量
WMUltrasonic Ultrasonic_3(3); //将3号口设置为超声波接口
WMDigitalTube DigitalTube_5(5); //将5号口设置为数码管接口
WMServo wmServo_2(2); //将2号口设置为二次开发接口

void setup(){
    delay(500);
}

void loop(){   
    distance = Ultrasonic_3.Distance(); //获取超声波检测到的距离
    if(((distance) > (10)) & ((distance) < (14))){  //如果该距离大于10cm小于14cm
        DigitalTube_5.setDisplay(0,distance); //数码管显示距离
        wmServo_2.runActionGroup(14,1); //运行14号动作组一次
        while(!(wmServo_2.getRunOverCmd()));  //检测动作组是否运行完毕
    }
    if(((distance) > (15)) & ((distance) < (18))){ //如果该距离大于15cm小于18cm
        DigitalTube_5.setDisplay(0,distance);
        wmServo_2.runActionGroup(15,1);
        while(!(wmServo_2.getRunOverCmd()));
    }
    if(((distance) > (19)) & ((distance) < (22))){ //如果该距离大于19cm小于22cm
        DigitalTube_5.setDisplay(0,distance);
        wmServo_2.runActionGroup(16,1);
        while(!(wmServo_2.getRunOverCmd()));
    }
    DigitalTube_5.setDisplay(0,distance);
    delay(100);    
}

