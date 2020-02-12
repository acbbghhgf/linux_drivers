/*************************************************************************
	> File Name: 09initlist.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 10时02分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Student{
public:
    Student(const string &name, int age, int no):m_name(name),m_age(age),m_no(no){}
    void who()
    {
        cout << "my name is "<< m_name << " , my age is " << m_age << " , my id is " << m_no << endl;
    }
private:
    string m_name;
    int m_age;
    int m_no;
};

int main()
{
    Student s("李辉", 34, 10011);
    s.who();

    return 0;
}
