#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

//1-6号舵机变量
double servo1_p;
double servo2_p;
double servo3_p;
double servo4_p;
double servo5_p;
double servo6_p;
WMServo wmServo_2(2);//将2号口设置为二次开发接口
WMIR ir_3(3);//将3号口设置为红外遥控接收模块接口

void setup(){
    ir_3.begin(); //初始化
    //将1-6号舵机的初始角度设为500
     servo1_p = 500;
    wmServo_2.setPosition(1,servo1_p,1000); //1号舵机在1000毫秒内转到servo1_p
     servo2_p = 500;
    wmServo_2.setPosition(2,servo2_p,1000);
     servo3_p = 500;
    wmServo_2.setPosition(3,servo3_p,1000);
     servo4_p = 500;
    wmServo_2.setPosition(4,servo4_p,1000);
     servo5_p = 500;
    wmServo_2.setPosition(5,servo5_p,1000);
     servo6_p = 500;
    wmServo_2.setPosition(6,servo6_p,1000);    
}

void loop(){    
    if(ir_3.keyPressedLong(34)){  //当长按红外遥控器上的PREV
        servo1_p += 20; //1号舵机角度加20
        wmServo_2.setPosition(1,servo1_p,100);//1号舵机在100毫秒内转到servo1_p
    }
    if(ir_3.keyPressedLong(194)){  //当长按红外遥控器上的PLAY/PAUSE
        servo1_p += -20;
        wmServo_2.setPosition(1,servo1_p,10);
    }
    if(ir_3.keyPressedLong(224)){  //当长按红外遥控器上的-
        servo2_p += 20;
        wmServo_2.setPosition(2,servo2_p,50);
    }
    if(ir_3.keyPressedLong(144)){  //当长按红外遥控器上的EQ
        servo2_p += -20;
        wmServo_2.setPosition(2,servo2_p,100);
    }
    if(ir_3.keyPressedLong(104)){  //当长按红外遥控器上的0
       servo3_p += 20;
        wmServo_2.setPosition(3,servo3_p,100);
    }
    if(ir_3.keyPressedLong(176)){  //当长按红外遥控器上的200+
        servo3_p += -20;
        wmServo_2.setPosition(3,servo3_p,100);
    }
    if(ir_3.keyPressedLong(48)){   //当长按红外遥控器上的1
        servo4_p += 20;
        wmServo_2.setPosition(4,servo4_p,100);
    }
    if(ir_3.keyPressedLong(122)){  //当长按红外遥控器上的3
        servo4_p += -20;
        wmServo_2.setPosition(4,servo4_p,100);
    }
    if(ir_3.keyPressedLong(16)){   //当长按红外遥控器上的4
        servo5_p += 20;
        wmServo_2.setPosition(5,servo5_p,100);
    }
    if(ir_3.keyPressedLong(90)){   //当长按红外遥控器上的6
        servo5_p += -20;
        wmServo_2.setPosition(5,servo5_p,100);
    }
    if(ir_3.keyPressedLong(66)){   //当长按红外遥控器上的7
        servo6_p += 20;
        wmServo_2.setPosition(6,servo6_p,100);
    }
    if(ir_3.keyPressedLong(82)){   //当长按红外遥控器上的9
        servo6_p += -20;
        wmServo_2.setPosition(6,servo6_p,100);
    }
    delay(50);
    ir_3.startDecode(); 
}

