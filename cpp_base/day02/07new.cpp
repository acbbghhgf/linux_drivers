/*************************************************************************
	> File Name: 07new.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 09时54分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int *pi = new int;
    *pi = 123;
    cout << "*pi = " << *pi << endl;
    delete pi;
    pi = NULL;

    int *p2 = new int(321);
    cout << "*p2 =  "<< *p2 << endl;
    delete p2;
    p2 = NULL;

    int *pa = new int[10];
    for(int i = 0; i< 10; i++)
    {
        pa[i] = i;
        cout << pa[i] << ' ';
    }
    cout << endl;
    delete[] pa;
    pa = NULL;

    int *pa2 = new int[10]{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for(int i = 0; i < 10; i++)
    {
        cout << pa2[i] << ' ';
    }
    cout << endl;
    delete[] pa2;
    pa2 = NULL;

    return 0;
}

