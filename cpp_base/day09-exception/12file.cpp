/*************************************************************************
	> File Name: 12file.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时52分27秒
 ************************************************************************/
#include <fstream>
#include<iostream>
using namespace std;

int main()
{
    ofstream ofs("file.txt");
    ofs << 12345 << ' ' << 6.78 << ' ' << "hello" << endl;
    ofs.close();

    ifstream ifs("file.txt");
    int i;
    double d;
    string s;
    ifs >> i >> d >> s;
    cout << i << ',' << d << ',' << s << endl;
    ifs.close();

    return 0;
}

