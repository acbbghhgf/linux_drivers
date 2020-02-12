/*************************************************************************
	> File Name: 09refArg.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 10时48分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

void swap1(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}


void swap2(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int main()
{
    int a = 3, b = 5;

    swap1(&a, &b);
    cout << "swap1(&a, &b) ==>" << " a =" << a << " b = " << b << endl;

    swap2(a, b);
    cout << "swap2(a, b) ==>" << " a = " << a << " b = " << b << endl;

    return 0;
}
