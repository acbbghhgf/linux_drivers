/*************************************************************************
	> File Name: 04this.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 21时30分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Counter{
public:
    Counter(int count=0):m_count(count){}
    Counter& add(void)
    {
        ++m_count;
        return *this;
    }
    void destroy(void)
    {
        cout << "this = " << this << endl;
        delete this;
    }
    int m_count;
};

int main()
{
    Counter cn;
    cn.add().add().add();
    cout << cn.m_count << endl;

    Counter *pcn = new Counter;
    cout << "pcn = " << pcn << endl;
    pcn->destroy();

    return 0;
}
