/*************************************************************************
	> File Name: 03integer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 21时42分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Integer{
public:
    Integer(int i):m_i(i){}
    void print()const{
        cout << m_i << endl;
    }
    const Integer operator-(void)const{
        Integer res(-m_i);
        return res;
    }
    friend const Integer operator~(const Integer &i)
    {
        Integer res(i.m_i * i.m_i);
        return res;
    }
private:
    int m_i;
};

int main()
{
    Integer i(100);
    Integer j = -i;
    j.print();
    j = ~i;
    j.print();

    return 0;
}
