/*************************************************************************
	> File Name: 05inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 10时44分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Base{
public:
    Base(void):m_i(0)
    {
        cout << "Base(void)" << endl;
    }
    Base(int i):m_i(i)
    {
        cout << "Base(int)" << endl;
    }
    Base(const Base& that):m_i(that.m_i){
        cout << "Base(const Base&)" << endl;
    }
    Base& operator=(const Base &that)
    {
        cout << "Base::operator=" << endl;
        if(&that != this)
        {
            m_i = that.m_i;
        }
        return *this;
    }
    int m_i;
};

class Derived:public Base{
public:
    Derived(void)
    {
        cout << "Derived(void)" << endl;
    }
    Derived(int i):Base(i),m_i(i)
    {
        cout << "Derived(int)" << endl;
    }
    Derived(const Derived& that):m_i(that.m_i),Base(that){
        cout << "Derived(const Derived&)" << endl;
    }
    Derived& operator=(const Derived &that)
    {
        cout << "Derived::operator=" << endl;
        if(&that != this)
        {
            Base::operator=(that);
            m_i = that.m_i;
        }
        return *this;
    }
    int m_i;
};

int main(void)
{
    Derived d1(123);
    Derived d2(d1);

    cout << d1.m_i << ',' << d1.Base::m_i << endl;
    cout << d2.m_i << ',' << d2.Base::m_i << endl;

    Derived d3;
    d3 = d1;
    cout << d3.m_i << ',' << d3.Base::m_i << endl;

    return 0;
}

