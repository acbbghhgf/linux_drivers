/*************************************************************************
	> File Name: 01complex.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 21时32分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Complex{
public:
    Complex(int r, int i):m_r(r),m_i(i){}
    void print(void)const{
        cout << m_r << '+' << m_i << 'i' << endl;
    }
    const Complex operator+(const Complex &c)const{
        Complex res(m_r + c.m_r, m_i + c.m_i);
        return res;
    }
private:
    int m_r;
    int m_i;
    
    friend const Complex operator-(const Complex &l, const Complex &r);
};

const Complex operator-(const Complex &l, const Complex &r)
{
    Complex res(l.m_r - r.m_r, l.m_i - r.m_i);
    return res;
}

int main()
{
    const Complex c1(1, 2);
    const Complex c2(3, 4);
    c1.print();
    c2.print();

    Complex c3 = c1 + c2;
    c3.print();

    c3 = c2 - c1;
    c3.print();

    return 0;
}
