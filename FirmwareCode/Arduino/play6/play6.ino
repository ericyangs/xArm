#include <Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

WMMatrixLed matrixLed_1(1);   //将1号口设为表情面板接口
unsigned char drawBuffer[16];
unsigned char *drawTemp;

void setup(){
    matrixLed_1.setColorIndex(1);
    matrixLed_1.setBrightness(6);   
}

void loop(){ //以下代码用wemake软件的表情面板设置画好图形，再生成代码复制进来
drawTemp = new unsigned char[16]{255,16,255,0,31,21,29,0,255,0,255,0,14,17,17,14};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);matrixLed_1.drawBitmap(0,0,16,drawBuffer);
    delay(1000);
drawTemp = new unsigned char[16]{0,0,65,127,65,16,96,0,7,8,15,8,7,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);matrixLed_1.drawBitmap(0,0,16,drawBuffer);
    delay(1000);
drawTemp = new unsigned char[16]{5,2,5,0,63,72,63,0,7,8,0,7,8,7,8,7};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);matrixLed_1.drawBitmap(0,0,16,drawBuffer);
    delay(1000); 
}

