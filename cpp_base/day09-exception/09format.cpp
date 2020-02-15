/*************************************************************************
	> File Name: 09format.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时42分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    cout << 100/3.0 << endl;
    cout.precision(10);
    cout << 100/3.0 << endl;

    cout << '[' ;
    cout.width(10);
    cout.fill('x');
    cout.setf(ios::showpos);
    cout.setf(ios::internal);
    cout << 12345 << ']' << endl;

    return 0;
}

