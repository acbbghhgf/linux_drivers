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

class B{
public:
    A m_a;
};

int main()
{
    B b;
    b.m_a.m_data = 12345;

    B b2(b);

    cout << b.m_a.m_data << endl;
    cout << b2.m_a.m_data << endl;

    return 0;
}
