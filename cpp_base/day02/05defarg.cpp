/*************************************************************************
	> File Name: 05defarg.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 09时38分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
void foo(int a, int b = 200, int c = 300);

int main()
{
    foo(10);
    foo(10, 20);
    foo(10, 20, 30);

    return 0;
}

void foo(int a, int b, int c)
{
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}
