/*************************************************************************
	> File Name: memptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 10时05分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Student{
public:
    Student(const string &name):m_name(name){}
    void who(void)
    {
        cout << "我叫" << m_name << endl;
    }
    string m_name;
};

int main()
{
    string Student::*pname = &Student::m_name;
    void (Student::*pwho)(void) = &Student::who;

    Student s("王建立");
    cout << s.*pname << endl;
    (s.*pwho)();

    return 0;
}
