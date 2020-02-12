/*************************************************************************
	> File Name: 06defarg.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月10日 星期一 09时45分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
void func(int a, int=0)
{
    cout << "a = " << a << endl;
}

int main()
{
    func(10, 20);
    func(10, 30);
    func(20, 30);
    return 0;
}
