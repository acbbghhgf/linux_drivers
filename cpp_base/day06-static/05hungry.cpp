/*************************************************************************
	> File Name: 05hungry.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 09时49分40秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Singleton{
public:
    static Singleton& getInstance(void)
    {
        return s_instance;
    }
    void print(void)const{
        cout << m_data << endl;
    }
private:
    Singleton(int data = 0):m_data(data)
    {
        cout << "单例对象被创建了" << endl;
    }
    Singleton(const Singleton&);
private:
    int m_data;
    static Singleton s_instance;
};

Singleton Singleton::s_instance(12345);

int main()
{
    cout << "main 函数开始执行" << endl;

    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();
    Singleton &s3 = Singleton::getInstance();

    cout << "&s1 = " << &s1 << ", &s2 = " << &s2 << ", &s3 = "<< &s3 << endl;
    s1.print();
    s2.print();
    s3.print();

    return 0;
}
