/*************************************************************************
	> File Name: 11string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时49分27秒
 ************************************************************************/
#include <sstream>
#include<iostream>
using namespace std;

int main()
{
    int i = 12345;
    double d = 6.78;
    string s = "hello";

    ostringstream oss;
    oss << i << ' ' << d << ' ' << s;
    cout << oss.str() << endl;

    istringstream iss;
    iss.str("54321 8.76 world");
    int i2;
    double d2;
    string s2;
    iss >> i2 >> d2 >> s2;
    cout << i2 << ',' << d2 << ',' << s2 << endl;

    return 0;
}

