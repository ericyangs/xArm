#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

WMServo wmServo_2(2);//将2号口设置为二次开发接口
WMMatrixLed matrixLed_5(5);//将5号口设为表情面板接口
unsigned char drawBuffer[16];
unsigned char *drawTemp;
WMLineFollower lineFollower_3(3);//将3号口设为循迹传感器接口

void setup(){
    matrixLed_5.setColorIndex(1);
    matrixLed_5.setBrightness(6);
    wmServo_2.runActionGroup(0,1);
    while(!(wmServo_2.getRunOverCmd()));
    drawTemp = new unsigned char[16]{0,24,60,126,219,153,24,24,24,24,153,219,126,60,24,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);matrixLed_5.drawBitmap(0,0,16,drawBuffer); 
}

void loop(){    //关于表情的代码用wemake软件的表情面板设置画好图形，再生成代码复制进来
    if(lineFollower_3.readSensorStatus(1)){//如果传感器1在黑线外，传感器2在黑线内
        for(int i=0;i<5000;i++) //重复执行5000次
        {
            if(lineFollower_3.readSensorStatus(2)){//如果传感器1在黑线内，传感器2在黑线外
                drawTemp = new unsigned char[16]{0,0,24,24,24,24,24,24,24,24,153,219,126,60,24,0};
                memcpy(drawBuffer,drawTemp,16);
                free(drawTemp);matrixLed_5.drawBitmap(0,0,16,drawBuffer);
                wmServo_2.setPosition(6,800,500); //6号舵机在500毫秒内转到800的位置
                delay(500);
            }
        }
    }
    if(lineFollower_3.readSensorStatus(2)){//如果传感器1在黑线内，传感器2在黑线外
        for(int i=0;i<5000;i++)
        {
            if(lineFollower_3.readSensorStatus(1)){//如果传感器1在黑线内，传感器2在黑线外
                drawTemp = new unsigned char[16]{0,24,60,126,219,153,24,24,24,24,24,24,24,24,0,0};
                memcpy(drawBuffer,drawTemp,16);
                free(drawTemp);matrixLed_5.drawBitmap(0,0,16,drawBuffer);
                wmServo_2.setPosition(6,100,500);
                delay(500);
            }
        }
    }
    if(lineFollower_3.readSensorStatus(0)){//如果传感器1和传感器2都在黑线外
        delay(200);
        if(lineFollower_3.readSensorStatus(0)){//如果传感器1和传感器2都在黑线外
            drawTemp = new unsigned char[16]{0,24,60,126,219,153,24,24,24,24,153,219,126,60,24,0};
            memcpy(drawBuffer,drawTemp,16);
            free(drawTemp);matrixLed_5.drawBitmap(0,0,16,drawBuffer);
            wmServo_2.setPosition(6,500,500);
            delay(500);
        }
    }   
}

