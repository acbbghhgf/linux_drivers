//#define LCD_VIDEO_ADDR	        (0x28000000)        // �Դ��ַ
#define LCD_VIDEO_ADDR	        (0x46000000)        // �Դ��ַ
#define LCD_BASE                (LCD_VIDEO_ADDR)    // �Դ��ַ

#define ROW		        (600)               //LCD�� ����
#define COL			(1024)               //LCD�� ����

#define X0                      (350)               //ͼƬ��ʾ�� X ��ʼλ��
#define Y0                      (200)               //ͼƬ��ʾ�� Y ��ʼλ��

#define W                       (320)               //logoͼƬ�߶�
#define H                       (200)               //logoͼƬ���


extern const unsigned char gImage_demo_logo[];
// ���
void lcd_draw_pixel(int row, int col, int color)
{
    unsigned long * pixel = (unsigned long  *)LCD_BASE;

    *(pixel + row * COL + col) = color;

}

// ����
void lcd_clear_screen(int color)
{
    int i, j;

    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            lcd_draw_pixel(i, j, color);

}

// ��ͼ
void lcd_draw_logo()
{
    int i, j;
    unsigned char *p = (unsigned char *)gImage_demo_logo;
    int blue, green, red;
    int color;

    // ����
    lcd_clear_screen(0x000000);
#if 1
    // ͼƬ��С320x200����
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

