/*************************************************************************
	> File Name: reinterpret_cast.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 21时53分50秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    char buf[] = "0001\00012345678\000123456";

    struct T{
        char type[5];
        char id[9];
        char passwd[7];
    };

    T* pt = reinterpret_cast<T*>(buf);
    cout << pt->type << endl;
    cout << pt->id << endl;
    cout << pt->passwd << endl;

    return 0;
}

