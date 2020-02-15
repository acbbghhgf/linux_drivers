/*************************************************************************
	> File Name: 07exception.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时28分40秒
 ************************************************************************/

#include<iostream>
using namespace std;
class FileError:public exception{
public:
    ~FileError(void) throw() {}
    const char *what(void) const throw(){
        cout << "文件错误处理" << endl;
        return "FileError";
    }
};

class MemoryError: public exception{
public:
    ~MemoryError(void) throw(){}
    const char *what(void)const throw(){
        cout << "内存错误处理" << endl;
        return "MemoryError";
    }
};

int main()
{
    try{
        char *p = new char[0xffffffff];
       // throw FileError();
        throw MemoryError();
        //...
    }
    catch(exception &ex)
    {
        cout << ex.what() << endl;
        return -1;
    }
    return 0;
}
