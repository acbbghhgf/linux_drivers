/*
    位置指针练习
*/
#include <stdio.h>
typedef struct {
    int id;
    float salary;
    char name[10];
} person;
int main() {
    int id = 0, size = 0;
    FILE *p_file = fopen("person.bin", "rb");
    if (p_file) {
        while (1) {
            size = fread(&id, sizeof(int), 1, p_file);
            if (!size) {
                break;
            }
            printf("id是%d\n", id);
            fseek(p_file, sizeof(person) - sizeof(int), SEEK_CUR);
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
