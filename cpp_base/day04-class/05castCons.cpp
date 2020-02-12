/*************************************************************************
	> File Name: 05castCons.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 09时48分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Integer{
public:
    Integer(void)
    {
        cout << "Integer(void)" << endl;
        m_data = 0;
    }
    Integer(int data)
    {
        cout << "Integer(int)" << endl;
        m_data = data;
    }
    void print(void)
    {
        cout << m_data << endl;
    }
private:
    int m_data;
};

int main()
{
    Integer i;
    i.print();

    i = 123;
    i.print();

    i = Integer(321);
    i.print();

    return 0;
}
