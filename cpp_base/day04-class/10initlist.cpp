/*************************************************************************
	> File Name: 10initlist.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 10时07分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A(int data)
    {
        cout << "A constructor func" << endl;
        m_data = data;
    }
    int m_data;
};

class B{
public:
    B(void):m_a(12345)
    {
        cout << "B constructor func" << endl;
    }
    A m_a;
};

int main()
{
    B b;
    return 0;
}
