/*************************************************************************
	> File Name: 09diamond.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 20时04分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    A(int data):m_data(data){
        cout << "A:" << this << "," << sizeof(A) << endl;
    }
protected:
    int m_data;
};

class B:virtual public A{
public:
    B(int data):A(data){
        cout << "B:" << this << "," << sizeof(B) << endl;
    }
    void set(int data)
    {
        m_data = data;
    }
};

class C:virtual public A{
public:
    C(int data):A(data)
    {
        cout << "C:" << this << "," << sizeof(C) << endl;
    }
    int get(void)
    {
        return m_data;
    }
};

class D:public B, public C{
public:
    D(int data):B(data),C(data),A(data)
    {
        cout << "D:" << this << "," << sizeof(D) << endl;
    }
};

int main()
{
    D d(100);
    cout << d.get() << endl;
    d.set(200);
    cout << d.get() << endl;
    return 0;
}

