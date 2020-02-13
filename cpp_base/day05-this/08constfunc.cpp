/*************************************************************************
	> File Name: 08constfunc.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 21时47分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A{
public:
    void func(void)const{
        cout << "func 常版本" << endl;
    }
    void func(void){
        cout << "func 非常版本" << endl;
    }
};

int main()
{
    A a;
    a.func();

    const A &ra = a;
    ra.func();
    return 0;
}
