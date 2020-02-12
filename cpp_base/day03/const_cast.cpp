/*************************************************************************
	> File Name: const_cast.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 21时51分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    const volatile int ci = 10;
    int *pci = const_cast<int *>(&ci);

    *pci = 20;
    cout << "ci = " << ci << endl;
    cout << "*pci = " << *pci << endl;
    cout << "&ci = " << (void *)&ci << endl;
    cout << "pci = " << pci << endl;

    return 0;
}

