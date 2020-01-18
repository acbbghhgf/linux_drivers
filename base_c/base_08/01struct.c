/*************************************************************************
	> File Name: 01struct.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 21时20分41秒
 ************************************************************************/

#include<stdio.h>
typedef struct{
    int age;
    float height;
    char name[10];
}sperson;

int main()
{
    sperson prsn1 = {20, 1.65f, "abc"};
    sperson prsn2 = {0};
    sperson *p_person = NULL;

    printf("年龄是%d\n", prsn1.age);
    printf("身高是%g\n", prsn1.height);
    printf("姓名是%s\n", prsn1.name);

    printf("请输入年龄：\n");
    scanf("%d", &prsn1.age);
    printf("请输入身高：\n");
    scanf("%g", &prsn1.height);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("请输入姓名：\n");
    fgets(prsn1.name, 10, stdin);

    printf("年龄是%d\n", prsn1.age);
    printf("身高是%g\n", prsn1.height);
    printf("姓名是%s\n", prsn1.name);

    prsn2 = prsn1;
    printf("年龄是%d\n", prsn2.age);
    printf("身高是%g\n", prsn2.height);
    printf("姓名是%s\n", prsn2.name);

    p_person = &prsn1;
    printf("年龄是%d\n", p_person->age);
    printf("身高是%g\n", p_person->height);
    printf("姓名是%s\n", p_person->name);

    return 0;

}

