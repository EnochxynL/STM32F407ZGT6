#include "run.h"
#include "run.hpp"

extern "C" {
	#include "lcd_test.h"
}

void setup() {
  // put your setup code here, to run once:
  SPI_LCD_Init();			// SPI LCD屏幕初始化
}

void loop() {
  // put your main code here, to run repeatedly:
  LCD_Test_Clear(); 		// 清屏测试
  LCD_Test_Text();			// 文本测试
  LCD_Test_Variable();		// 变量显示，包括整数和小数
  LCD_Test_Color();			// 颜色测试
  LCD_Test_Grahic();		// 2D图形绘制	
  LCD_Test_Image();			// 图片显示
  LCD_Test_Direction();	// 更换显示方向	
}