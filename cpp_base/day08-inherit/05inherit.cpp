/*************************************************************************
	> File Name: 05inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 10时44分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Member{
public:
    Member(void):m_i(0){
        cout << "Member(void)" << endl;
    }
    Member(int i):m_i(i)
    {
        cout << "Member(int)" << endl;
    }
    int m_i;
};

class Base{
public:
    Base(void):m_i(0)
    {
        cout << "Base(void)" << endl;
    }
    Base(int i):m_i(i)
    {
        cout << "Base(int)" << endl;
    }
    int m_i;
};

class Derived:public Base{
public:
    Derived(void)
    {
        cout << "Derived(void)" << endl;
    }
    Derived(int i):Base(i),m_mem(i)
    {
        cout << "Derived(int)" << endl;
    }
    Member m_mem;
};

int main(void)
{
    Derived d;
    cout << d.m_i << ',' << d.m_mem.m_i << endl;

    Derived d2(123);
    cout << d2.m_i << ',' << d2.m_mem.m_i << endl;

    return 0;
}

