#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

double count; //计数变量
double Time;  //计时变量
double sound; //声音检测变量
WMDigitalTube DigitalTube_5(5); //将5号口设置为数码管接口
WMSound Sound_4(4); //将4号口设置为声音检测模块接口
WMServo wmServo_2(2); //将2号口设置为二次开发接口

void setup(){
    count = 0;  //初始化计数变量
    Time = 0;   //初始化计时变量
    sound = 0;  //初始化声音检测变量
    DigitalTube_5.setDisplay(0,count);   //初始化数码管显示
}

void loop(){    
    if(((Sound_4.getSound()) > (80)) & (((sound)==(0)))){ //如果检测到声音大于80且声音检测变量为0
        Time = 0; //将计时置为0
        sound = 1;  //将声音检测变量置为1
        count += 1; //将计数值加1
        DigitalTube_5.setDisplay(0,count);  //数码管显示计数值
        delay(100);
    }
    if((Sound_4.getSound()) < (60)){  //如果检测到声音小于60
        sound = 0;  //将声音检测变量置为0
    }
    if((count) > (0)){  //如果计数值大于0
        Time += 1;  //计时加1
        if((Time) > (4000)){  //如果计时大于4000
            wmServo_2.runActionGroup(count,1);  //运行count号动作组一次
            while(!(wmServo_2.getRunOverCmd()));
            Time = 0; //将计时重置
            count = 0;  //将计数重置
            DigitalTube_5.setDisplay(0,count);  //数码管显示计数值
        }
    }    
}

