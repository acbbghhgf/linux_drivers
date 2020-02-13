/*************************************************************************
	> File Name: 06lary.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 09时56分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Singleton{
public:
    static Singleton &getInstance(void)
    {
        if(s_instance == NULL)
        {
            s_instance = new Singleton(12345);
        }
        s_count++;
        return *s_instance;
    }
    void release(void)
    {
        if(--s_count == 0)
        {
            delete s_instance;
            s_instance = NULL;
        }
    }
    void print(void)const
    {
        cout << m_data << endl;
    }
private:
    Singleton(int data=0):m_data(data)
    {
        cout << "单例对象被创建" << endl;
    }
    Singleton(const Singleton&);
    ~Singleton(void)
    {
        cout << "单例对象被销毁" << endl;
    }
private:
    int m_data;
    static Singleton *s_instance;
    static int s_count;
};

Singleton *Singleton::s_instance = NULL;
int Singleton::s_count = 0;

int main()
{
    cout << "main 函数开始执行" << endl;
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();
    Singleton &s3 = Singleton::getInstance();

    cout << "&s1 = " << &s1 << ", &s2 = " << &s2 << " , &s3 = " << &s3 << endl;

    s1.print();
    s1.release();

    s2.print();
    s3.print();

    s2.release();
    s3.release();

    return 0;
}
