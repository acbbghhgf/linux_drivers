/*************************************************************************
	> File Name: 02inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 10时39分48秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Base{
public:
    void func(void)
    {
        cout << "Base::func(void)" << endl;
    }
};

class Derived:public Base{
public:
    void func(int i)
    {
        cout << "Derived::func(int)" << endl;
    }
};

int main(void)
{
    Derived d;
    d.Base::func();
    d.func(10);
    return 0;
}

