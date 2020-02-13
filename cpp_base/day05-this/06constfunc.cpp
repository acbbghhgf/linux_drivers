/*************************************************************************
	> File Name: 06constfunc.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 21时41分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    A(int data = 0):m_data(data){}
    void print(void) const{
        cout << m_data++ << endl;
    }
private:
    mutable int m_data;
};

int main()
{
    A a(100);
    a.print();
    a.print();
    a.print();

    return 0;
}
