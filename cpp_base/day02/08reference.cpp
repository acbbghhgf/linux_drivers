/*************************************************************************
	> File Name: 08reference.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 10时40分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int a = 66;
    int &b = a;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;

    b++;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
