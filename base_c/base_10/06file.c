/*************************************************************************
	> File Name: 06file.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 22时35分44秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
typedef struct{
    int id;
    float salary;
    char name[10];
}person;
int main()
{
    int choice = 1;
    person prsn = {0};
    FILE *p_file = fopen("person.bin", "ab");
    if(p_file)
    {
        while(choice)
        {
            printf("请输入id :\n");
            scanf("%d", &prsn.id);
            printf("请输入工资：\n");
            printf("%g", &prsn.salary);
            scanf("%*[^\n]");
            scanf("%*c");
            printf("请输入姓名：\n");
            fgets(prsn.name, 10, stdin);
            if(strlen(prsn.name) == 9 && prsn.name[8] != '\n')
            {
                scanf("%*[^\n]");
                scanf("%*c");
            }
            fwrite(&prsn, sizeof(person), 1, p_file);
            printf("是否需要输入下一个人员信息？0表示不需要，1表示需要\n");
            scanf("%d", &choice);
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
