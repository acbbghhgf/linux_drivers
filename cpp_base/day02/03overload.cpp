/*************************************************************************
	> File Name: 03overload.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 09时26分41秒
 ************************************************************************/

#include<iostream>
using namespace std;
int foo(int i)
{
    cout << "foo(int)" << endl;
}

void foo(int i, int j)
{
    cout << "foo(int i, int j)" << endl;
}

void foo(int a, float f)
{
    cout << "foo(int a, float f)" << endl;
}

int main()
{
    foo(10);

    foo(10, 20);
    foo(10, 1.23f);

    void (*pfoo)(int, float) = foo;

    pfoo(10, 20);
    return 0;
}
