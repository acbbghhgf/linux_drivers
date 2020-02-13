/*************************************************************************
	> File Name: 08new.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 22时04分08秒
 ************************************************************************/
#include <cstdlib>
#include<iostream>
using namespace std;
class A{
public:
    A(void){
        cout << "A的构造函数" << endl;
    }
    ~A(void)
    {
        cout << "A的析构函数" << endl;
    }
    static void *operator new(size_t size)
    {
        cout << "A::new" << endl;
        void *pv = malloc(size);
        return pv;
    }
    static void operator delete(void *pv)
    {
        cout << "A::delete" << endl;
        free(pv);
    }
};

int main()
{
    A *pa = new A;

    delete pa;
    return 0;
}
