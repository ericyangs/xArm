#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

WMUltrasonic Ultrasonic_3(3); //将3号口设置为超声波接口
WMServo wmServo_2(2); //将2号口设置为二次开发接口

void setup(){
    delay(500); //开启时延时500毫秒后开始工作
}

void loop(){    
    if((Ultrasonic_3.Distance()) < (20)){ //如果超声波检测的距离小于20cm，则执行以下程序
        wmServo_2.runActionGroup(21,1); //运行21号动作组一次
        while(!(wmServo_2.getRunOverCmd()));  //直到检测到动作组运行完毕
    }   
}

