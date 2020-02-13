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
    static void func1(void)
    {
        cout << "静态成员函数" << endl;
        cout << s_data << endl;
    }
    void func2(void)
    {
        cout << "非静态成员函数" << endl;
        cout << s_data << endl;
        cout << m_data << endl;
    }
    int m_data;
    static int s_data;
};

int A::s_data = 100;

int main()
{
    A::func1();

    A a(200);
    a.func2();

    return 0;
}
