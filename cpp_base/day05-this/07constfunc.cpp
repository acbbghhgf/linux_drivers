/*************************************************************************
	> File Name: 07constfunc.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 21时44分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    void func1(void)const
    {
        cout << "常函数" << endl;
    }
    void func2(void){
        cout << "非 常函数" << endl;
    }
};

int main()
{
    A a;
    a.func1();
    a.func2();

    const A a2 = a;
    a2.func1();
    //a2.func2();

    const A &ra = a;
    ra.func1();
    ra.func2();

    return 0;
}
