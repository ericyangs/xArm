#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

WMPotentiometer Potentiometer_4(4);//将4号口设置为电位器模块接口
WMRGBLed rgbLED_5(5);//将5号口设置为rgb模块接口
WMButton buttonSensor_3(3);//将3号口设置为触摸按钮模块接口
WMServo wmServo_2(2);//将2号口设置为二次开发接口

void setup(){
}

void loop(){   
    if((Potentiometer_4.getPtm()) < (20)){//如果电位器的值小于20
        rgbLED_5.setColor(0,255,0,0); //将rgb灯颜色设置为红255，绿0，蓝0
        rgbLED_5.show();  //显示颜色
        if((buttonSensor_3.pressed()==1)){ //如果检测到触摸
            wmServo_2.runActionGroup(1,1);//运行1号动作组一次
            while(!(wmServo_2.getRunOverCmd()));
        }
    }
    if(((Potentiometer_4.getPtm()) > (40)) & ((Potentiometer_4.getPtm()) < (60))){
        rgbLED_5.setColor(0,0,255,0);//将rgb灯颜色设置为红0，绿255，蓝0
        rgbLED_5.show();
        if((buttonSensor_3.pressed()==1)){
            wmServo_2.runActionGroup(2,1);
            while(!(wmServo_2.getRunOverCmd()));
        }
    }
    if((Potentiometer_4.getPtm()) > (80)){
        rgbLED_5.setColor(0,0,0,255);
        rgbLED_5.show();
        if((buttonSensor_3.pressed()==1)){
            wmServo_2.runActionGroup(3,1);
            while(!(wmServo_2.getRunOverCmd()));
        }
    }   
}

