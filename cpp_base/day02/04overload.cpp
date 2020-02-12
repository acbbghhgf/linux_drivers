/*************************************************************************
	> File Name: 04overload.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 09时33分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
void bar(int i)
{
    cout << "bar(1) bar(int i)" << endl;
}

void bar(const char c)
{
    cout << "bar(2) bar(const char c)" << endl;
}

void func(char c)
{
    cout << "func(1) func(char c)" << endl;
}

void func(int i)
{
    cout << "func(2) func(int i)" << endl;
}

void hum(int i, ...)
{
    cout << "hum(1) hum(int i, ...)" << endl;
}

void hum(int i, int j)
{
    cout << "hum(2) hum(int i, int j)" << endl;
}

int main()
{
    char c = 'c';
    bar (c);
    short s = 10;
    func(s);
    hum(10, 1.23);

    return 0;
}
