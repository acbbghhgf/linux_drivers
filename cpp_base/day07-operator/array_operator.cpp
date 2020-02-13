/*************************************************************************
	> File Name: array_operator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 21时58分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Array{
public:
    Array(size_t size)
    {
        m_arr = new int[size];
        m_size = size;
    }
    int &operator[](size_t i)
    {
        return m_arr[i];
    }
    const int &operator[](size_t i)const{
        return m_arr[i];
    }
private:
    int *m_arr;
    size_t m_size;
};

int main()
{
    Array arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    const Array &rarr = arr;
    cout << rarr[0] << endl;
    cout << rarr[1] << endl;
    cout << rarr[2] << endl;

    return 0;
}
