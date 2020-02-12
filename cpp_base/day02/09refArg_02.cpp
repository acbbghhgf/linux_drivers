/*************************************************************************
	> File Name: 09refArg_02.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 10时52分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Student{
    char name[128];
    int age;
    int no;
};

void print(const Student &s)
{
    cout << "my name is " <<  s.name << ", this year" << s.age << "year, id = "<< s.no << endl;
}

int main()
{
    const Student stu = {"Mr.wang", 45, 10086};
    print(stu);
    print(stu);
    print(stu);

    return 0;
}
