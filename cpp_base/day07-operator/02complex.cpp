/*************************************************************************
	> File Name: 02complex.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 21时38分15秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Complex{
public:
    Complex(int r, int i):m_r(r),m_i(i){}
    void print(){
        cout << m_r << '+' << m_i << 'i' << endl;
    }
    Complex &operator+=(const Complex &c)
    {
        m_r += c.m_r;
        m_i += c.m_i;
        return *this;
    }
    friend Complex &operator-=(Complex &l, const Complex &r)
    {
        l.m_r -= r.m_r;
        l.m_i -= r.m_i;
        return l;
    }
private:
    int m_r;
    int m_i;
};

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);

    c1 += c2;
    c1.print();

    c1 -= c2;
    c1.print();

    return 0;
}
