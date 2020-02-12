/*************************************************************************
	> File Name: 06cpCons.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 09时51分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A(int data = 0)
    {
        cout << "A(int=0)" << endl;
        m_data = data;
    }
    A(const A& that)
    {
        cout << "A(const A&)" << endl;
        m_data = that.m_data;
    }
    int m_data;
};

void foo(A a){}

A bar(void)
{
    A a;
    cout << "&a = " << &a << endl;
    return a;
}

int main()
{
    A a1;
    A a2 = a1;
    foo(a1);

    A a3 = bar();
    cout << "&a3 = " << &a3 << endl;

    return 0;
}
