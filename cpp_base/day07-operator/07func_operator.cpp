/*************************************************************************
	> File Name: 07func_operator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 22时02分09秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Func{
public:
    double operator()(double x)
    {
        return x*x;
    }
    int operator()(int x, int y)
    {
        return x + y;
    }
};

int main()
{
    Func func;
    cout << func(3, 3) << endl;
    cout << func(10 ,20) << endl;

    return 0;
}
