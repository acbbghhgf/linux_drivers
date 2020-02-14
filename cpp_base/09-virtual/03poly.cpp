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
    Base(void)
    {
        cout << "Base的构造函数" << endl;
    }
    virtual ~Base(void)
    {
        cout << "Base的析构函数" << endl;
    }
};

class Derived:public Base{
public:
    Derived(void)
    {
        cout << "Derived的构造函数" << endl;
    }
    ~Derived(void)
    {
        cout << "Derived的析构函数" << endl;
    }
};

int main()
{
    Base *pb = new Derived;

    delete pb;
    return 0;
}
