/*************************************************************************
	> File Name: 08mul_inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 19时53分40秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Base1{
public:
    void func(void)
    {
        cout << "Base1::func(void)" << endl;
    }
};

class Base2{
public:
    void func(int i)
    {
        cout << "Base2::func(int)" << endl;
    }
};

class Derived: public Base1, public Base2
{
public:
//    using Base1::func;
//    using Base2::func;
};

int main()
{
    Derived d;
  //  d.func();
//    d.func(10);

    d.Base1::func();
    d.Base2::func(10);
    return 0;
}
