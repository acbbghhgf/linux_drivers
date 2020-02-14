/*************************************************************************
	> File Name: 06typeid.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 20时47分26秒
 ************************************************************************/
#include <typeinfo>
#include<iostream>
using namespace std;
class A{virtual void foo(void){}};
class B:public A{void foo(void){}};
class C:public A{void foo(void){}};

void func(A& ra)
{
    if(typeid(ra) == typeid(B))
    {
        cout << "针对B子类对象的处理" << endl;
    }
    else if(typeid(ra) == typeid(C))
    {
        cout << "针对C子类对象的处理" << endl;
    }
}

int main()
{
    int i;
    cout << typeid(int).name() << endl;
    cout << typeid(i).name() << endl;

    int *a1[10];
    int (*a2)[10];
    cout << typeid(a1).name() << endl;
    cout << typeid(a2).name() << endl;
    cout << typeid(int (*[10])(char)).name() << endl;

    B b;
    func(b);
    C c;
    func(c);

    return 0;
}
