/*************************************************************************
	> File Name: 04exception.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时17分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
class ErrorA{};
class ErrorB:public ErrorA{};
void func(void)
{
    //throw ErrorA();
    throw ErrorB();
}

int main()
{
    try{
        func();
    }
    catch(ErrorB &ex)
    {
        cout << "针对ErrorB处理" << endl;
        return -1;
    }
    catch(ErrorA &ex)
    {
        cout << "针对ErrorA处理" << endl;
        return -1;
    }
    return 0;
}
