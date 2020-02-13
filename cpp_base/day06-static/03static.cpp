/*************************************************************************
	> File Name: 03static.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 09时42分02秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    A(int data=0):m_data(data){}
    int m_data;
    static int s_data;
};

int A::s_data = 100;

int main()
{
    A a(100);
    cout << sizeof(a) << endl;

    cout << A::s_data << endl;
    cout << a.m_data << endl;
    cout << a.s_data << endl;

    A a2(a);
    a2.m_data  = 222;
    a2.s_data = 111;

    cout << a.s_data << endl;
    cout << a.m_data << endl;

    return 0;
}
