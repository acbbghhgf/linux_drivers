/*************************************************************************
	> File Name: 08exception.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时33分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    A(void){ cout << "A的构造函数" << endl; }
    ~A(void){ cout << "A的析构函数" << endl; }
};

class B{
public:
    B(void):m_a(new A){
        if("error")
        {
            delete m_a;
            throw -1;
        }
    }
    ~B(void){
        delete m_a;
    }
    A *m_a;
};

int main()
{
    try{
        B b;
    }
    catch(int ex)
    {
        cout << "捕获到异常：" << ex << endl;
        return 0;
    }
    return 0;
}
