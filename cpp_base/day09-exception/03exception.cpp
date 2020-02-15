/*************************************************************************
	> File Name: 03exception.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时09分53秒
 ************************************************************************/
#include <cstdio>
#include<iostream>
using namespace std;
class FileError{
public:
    FileError(const string &file, int line):m_file(file),m_line(line){
        cout << "出错位置：" << m_file << "," << m_line << endl;
    }
private:
    string m_file;
    int m_line;
};

class A{
public:
    A(void){cout << "A的构造函数" << endl;}
    ~A(void){cout << "A的析构函数" << endl;}
};

int func3(){
    A a;
    FILE *fp = fopen("xx.txt", "r");
    if(fp == NULL)
    {
        //throw FileError(__FILE__, __LINE__);
        throw -1;
    }
    cout << "func3 正常运行" << endl;
    return 0;
}

int func2()
{
    A a;
    func3();
    cout << "func2正常运行" << endl;
    return 0;
}

int func1()
{
    A a;
    func2();
    cout << "func1正常运行" << endl;
    return 0;
}

int main()
{
    try{
        func1();
        cout << "main正常运行" << endl;
    }
    catch(int ex)
    {
        if(ex == -1)
        {
            cout << "file open fail!" << endl;
            return -1;
        }
    }
    catch(FileError &ex)
    {
        cout << "file open fail!" << endl;
        return -1;
    }
    return 0;
}
