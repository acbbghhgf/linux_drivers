/*************************************************************************
	> File Name: 02poly.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 20时40分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Base{
public:
    virtual int cal(int a, int b)
    {
        return a + b;

    }
    void func(void)
    {
        cout << cal(10, 20) << endl;
    }
};

class Derived:public Base{
public:
    int cal(int a, int b)
    {
        return a* b;
    }
};

int main()
{
    Derived d;
    Base b = d;
    cout << b.cal(10,20) << endl;

    d.func();
    return 0;
}
