/*************************************************************************
	> File Name: 04defCons.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 09时18分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A(void)
    {
        cout << "A 的无参构造函数" << endl;
        m_data = 12345;
    }
    int m_data;
};

class B{
public:
    int m_num;
    A m_a;
};

int main()
{
    B b;
    cout << "b.m_num " << b.m_num << endl;
    cout << "b.m_a.m_data " << endl;

    return 0;
}

