/*************************************************************************
	> File Name: 04integer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 21时47分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Integer{
public:
    Integer(int i):m_i(i){}
    void print()const{
        cout << m_i << endl;
    }
    Integer &operator++(){
        ++m_i;
        return *this;
    }
    friend Integer &operator--(Integer &i)
    {
        --i.m_i;
        return i;
    }
    const Integer operator++(int)
    {
        Integer old = *this;
        ++m_i;
        return old;
    }
    friend const Integer operator--(Integer &i, int)
    {
        Integer old = i;
        --i.m_i;
        return old;
    }
private:
    int m_i;
};

int main()
{
    Integer i(100);
    Integer j = ++i;
    j.print();
    i.print();

    j = ++++i;
    j.print();
    i.print();

    j = --i;
    j.print();
    i.print();
    j = ----i;
    j.print();
    i.print();

    j = i++;
    j.print();
    i.print();

    j = i--;
    j.print();
    i.print();

    return 0;
}
