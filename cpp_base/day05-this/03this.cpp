/*************************************************************************
	> File Name: 03this.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 21时25分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

class User{
public:
    User(const string &m_name, int m_age)
    {
        this->m_name = m_name;
        this->m_age = m_age;
    }
    void print(void)
    {
        cout << "my name is " << this->m_name << " , my age is " << this->m_age << endl;
    }
private:
    string m_name;
    int m_age;
};

int main()
{
    User u1("张三", 22);
    cout << "&u1 = " << &u1 << endl;

    User u2("李四", 23);
    cout << "&u2 = " << &u2 << endl;

    u1.print();
    u2.print();
    return 0;
}

