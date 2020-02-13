/*************************************************************************
	> File Name: 10destructor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 22时17分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    A(void){
        cout << "A::A(void)" << endl;
    }
    ~A(void){
        cout << "A::~A(void)" << endl;
    }
};

class B{
public:
    B(void)
    {
        cout << "B::B(void)" << endl;
    }
    ~B(void)
    {
        cout << "B::~B(void)" << endl;
    }
    A m_a;
};

int main()
{
    B b;
    return 0;
}
