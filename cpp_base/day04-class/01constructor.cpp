/*************************************************************************
	> File Name: 01constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 08时39分10秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Student{
public:
    Student(const string &name, int age, int no)
    {
        cout << "constructor func "<< endl;
        m_name = name;
        m_age = age;
        m_no = no;
    }
    void who(void)
    {
        cout << "my name is " << m_name << ", this year is " << m_age << ", id is " << m_no << endl;
    }

private:
    string m_name;
    int m_age;
    int m_no;
};

int main()
{
    Student s("lihui", 35, 10110);
    s.who();

    return 0;
}
