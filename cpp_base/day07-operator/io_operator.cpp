/*************************************************************************
	> File Name: io_operator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 21时53分48秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Complex{
public:
    Complex(int r, int i):m_r(r),m_i(i){}
    friend ostream& operator<<(ostream& os, const Complex &c)
    {
        os << c.m_r << '+' << c.m_i << 'i';
        return os;
    }
    friend istream &operator>>(istream &is, Complex &c)
    {
        is >> c.m_r >> c.m_i;
        return is;
    }
private:
    int m_r;
    int m_i;
};

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);

    cout << c1 << endl;
    cout << c1 << ',' << c2 << endl;
    cout << "请输入一个复数" << endl;
    cin >> c1;
    cout << c1 << endl;
    return 0;
}

