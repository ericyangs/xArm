#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

double touch; //触摸变量
WMDigitalTube DigitalTube_5(5);//将5号口设置为数码管接口
WMButton buttonSensor_3(3);//将3号口设置为触摸按钮模块接口
WMServo wmServo_2(2);//将2号口设置为二次开发接口

void setup(){
    touch = 0;//初始化变量
    DigitalTube_5.setDisplay(0,touch);  //初始化数码管显示
}

void loop(){  
    if((buttonSensor_3.pressed()==1)){   //如果检测到触摸
        while(buttonSensor_3.pressed()==1)  //如果一直检测到触摸
        {
            delay(100);
            touch += 0.1; //将触摸变量加0.1
            DigitalTube_5.setDisplay(0,touch);//数码管显示触摸变量值
        }
    }
    if((touch) > (0)){  //如果触摸变量值大于0
        if(((touch) > (1)) & ((touch) < (2))){  //如果触摸变量值大于1小于2
            wmServo_2.runActionGroup(1,1);  //执行1号动作组一次
            while(!(wmServo_2.getRunOverCmd()));
        }
        if(((touch) > (2)) & ((touch) < (3))){
            wmServo_2.runActionGroup(2,1);
            while(!(wmServo_2.getRunOverCmd()));
        }
        if(((touch) > (3)) & ((touch) < (4))){
            wmServo_2.runActionGroup(3,1);
            while(!(wmServo_2.getRunOverCmd()));
        }
        touch = 0;  //重置变量
        DigitalTube_5.setDisplay(0,touch);  //重置显示
    }    
}

