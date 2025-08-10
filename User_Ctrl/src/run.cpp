#include "run.h"
#include <rtthread.h>
extern "C" {
#include "lcd_spi_154.h"
#include "lcd_test.h"
}

static struct rt_thread lcd_thread;   //demo,用户定义的线程句柄
static char lcd_thread_stack[1024];    //demo,用户定义的静态线程大小
static void lcd_thread_entry(void* parameter) {
	while (1)
	{
    LCD_Test_Clear(); 		// 清屏测试
    LCD_Test_Text();			// 文本测试
    LCD_Test_Variable();	// 变量显示，包括整数和小数
    LCD_Test_Color();			// 颜色测试
    LCD_Test_Grahic();		// 2D图形绘制	
    LCD_Test_Image();			// 图片显示
    LCD_Test_Direction();	// 更换显示方向	
	}
}

void setup() {
  // put your setup code here, to run once:
  SPI_LCD_Init();			// SPI LCD屏幕初始化
	rt_thread_init(&lcd_thread, "LCD_Test", &lcd_thread_entry, RT_NULL, &lcd_thread_stack[0], sizeof(lcd_thread_stack), 3, 20);
	rt_thread_startup(&lcd_thread);
}

void loop() {
  // put your main code here, to run repeatedly:
}