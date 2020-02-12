/*************************************************************************
	> File Name: 08constref.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 10时44分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

int func(void)
{
    int num = 123;
    return num;
}

int main()
{
    const int &res = func();
    cout << res << endl;

    const int & ri = 100;
    int i = 200;
    
    const double &rd = i;
    cout << "&i = " << &i << endl;
    cout << "&rd = " << &rd << endl;
    cout << "rd = " << rd << endl;

    return 0;
}

