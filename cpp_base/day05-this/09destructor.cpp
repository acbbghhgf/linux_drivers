/*************************************************************************
	> File Name: 09destructor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 21时51分54秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Integer{
public:
    Integer(int data = 0): m_data(new int(data)){}
    void print(void)const{
        cout << *m_data << endl;
    }
    ~Integer(void)
    {
        cout << "Integer 析构函数" << endl;
        delete m_data;
        m_data = NULL;
    }
private:
    int *m_data;
};

int main()
{
    if(1)
    {
        Integer i(100);
        i.print();
        cout << "test 1" << endl;
        Integer *pi = new Integer(200);
        pi->print();
        delete pi;
        cout << "test3" << endl;
    }
    cout << "test2" << endl;
    return 0;
}
