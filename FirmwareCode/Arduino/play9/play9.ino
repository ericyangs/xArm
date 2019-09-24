#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

WMButton buttonSensor_3(3);//将3号口设置为触摸按钮模块接口
WMPotentiometer Potentiometer_4(4);//将4号口设置为电位器模块接口
WMServo wmServo_2(2);//将2号口设置为二次开发接口

void setup(){
}

void loop(){    
    if((buttonSensor_3.pressed()==1)){  //如果检测到触摸
        if((Potentiometer_4.getPtm()) < (20)){  //如果电位器的值小于20
            wmServo_2.setActionSpeed(100);  //将运行速度设置为100
            wmServo_2.runActionGroup(1,1);  //运行1号动作组一次
            while(!(wmServo_2.getRunOverCmd()));
        }
        if(((Potentiometer_4.getPtm()) > (40)) & ((Potentiometer_4.getPtm()) < (60))){
            wmServo_2.setActionSpeed(150);
            wmServo_2.runActionGroup(1,1);
            while(!(wmServo_2.getRunOverCmd()));
        }
        if((Potentiometer_4.getPtm()) > (80)){
            wmServo_2.setActionSpeed(200);
            wmServo_2.runActionGroup(1,1);
            while(!(wmServo_2.getRunOverCmd()));
        }
    }   
}

