/*************************************************************************
	> File Name: 11copy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 22时20分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Integer{
public:
    Integer(int data = 0):m_data(new int(data)){}
    void print(void)const{
        cout << *m_data << endl;
    }
    ~Integer(void)
    {
        cout << "Integer 析构函数" << endl;
        delete m_data;
        m_data = NULL;
    }
    Integer(const Integer &that)
    {
        cout << "自定义深拷贝" << endl;
        m_data = new int(*that.m_data);
    }
private:
    int *m_data;
};

int main()
{
    Integer i1(100);
    Integer i2 = i1;
    i1.print();
    i2.print();
    return 0;
}
