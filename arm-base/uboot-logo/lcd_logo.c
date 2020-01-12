//#define LCD_VIDEO_ADDR	        (0x28000000)        // 显存地址
#define LCD_VIDEO_ADDR	        (0x46000000)        // 显存地址
#define LCD_BASE                (LCD_VIDEO_ADDR)    // 显存地址

#define ROW		        (600)               //LCD屏 行数
#define COL			(1024)               //LCD屏 列数

#define X0                      (350)               //图片显示的 X 起始位置
#define Y0                      (200)               //图片显示的 Y 起始位置

#define W                       (320)               //logo图片高度
#define H                       (200)               //logo图片宽度


extern const unsigned char gImage_demo_logo[];
// 描点
void lcd_draw_pixel(int row, int col, int color)
{
    unsigned long * pixel = (unsigned long  *)LCD_BASE;

    *(pixel + row * COL + col) = color;

}

// 清屏
void lcd_clear_screen(int color)
{
    int i, j;

    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            lcd_draw_pixel(i, j, color);

}

// 画图
void lcd_draw_logo()
{
    int i, j;
    unsigned char *p = (unsigned char *)gImage_demo_logo;
    int blue, green, red;
    int color;

    // 清屏
    lcd_clear_screen(0x000000);
#if 1
    // 图片大小320x200像素
    for (i = Y0; i < (Y0 + H); i++)
        for (j = X0; j < (X0 + W); j++)
        {
            blue  = *p++;
            green = *p++;
            red   = *p++;

            color = red << 16 | green << 8 | blue << 0;
            lcd_draw_pixel(i, j, color);
        }
#endif
}

