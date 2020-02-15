/*************************************************************************
	> File Name: 06exception.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时26分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Base{
public:
    virtual void func(void)throw(int){}
    virtual ~Base(void)throw(){}
};

class Derived:public Base{
public:
    void func(void)throw(){}
    ~Derived(void)throw(){}
};

int main()
{
    return 0;
}
