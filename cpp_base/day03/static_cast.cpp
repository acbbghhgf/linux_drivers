/*************************************************************************
	> File Name: static_cast.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 21时47分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int *pi = NULL;
    char c = long(pi);

    void *pv = pi;
    pi = static_cast<int *>(pv);
    c = (long)pi;
    c = static_cast<long>(pi);

    return 0;
}

