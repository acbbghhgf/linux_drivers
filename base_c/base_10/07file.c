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
    int size = 0;
    person prsn = {0};
    FILE *p_file = fopen("person.bin", "rb");
    if(p_file)
    {
        while(1)
        {
            size = fread(&prsn, sizeof(person), 1, p_file);
            if(!size)
            {
                break;
            }
            printf("id = %d\n", prsn.id);
            printf("salary = %d\n", prsn.salary);
            printf("name = %s\n", prsn.name);
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
