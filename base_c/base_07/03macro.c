/*************************************************************************
	> File Name: 03macro.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月15日 星期三 07时40分22秒
 ************************************************************************/

#include<stdio.h>
#define     ABS(n) n >= 0? n : 0 -n
#define     NEG(n) n = 0 - n

int abs(int num)
{
    if(num >= 0)
    {
        return num;
    }
    else{
        return 0 - num;
    }
}

void neg(int *p_num)
{
    *p_num = 0 - *p_num;
}

int main(){
    int num = 0;
    printf("请输入一个数字:\n");
    scanf("%d", &num);
    printf("abs(num) = %d\n", abs(num));
    printf("ABS(num) = %d\n", ABS(num));
    neg(&num);
    printf("num = %d\n", num);
    NEG(num);
    printf("num = %d\n", num);
    return 0;
}
