/*************************************************************************
	> File Name: 05exception.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时20分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
class FileError{};
class MemoryError{};

void func(void) throw(FileError, MemoryError, int);
void func(void) throw(int, FileError, MemoryError){
    throw -1;
    throw MemoryError();
    throw FileError();
}

int main()
{
    try{
        func();
    }
    catch(FileError &ex){
        cout << "文件错误处理" << endl;
        return -1;
    }
    catch(MemoryError &ex){
        cout << "内存错误的处理" << endl;
        return -1;
    }
    catch(int ex){
        cout << "int 错误处理" << endl;
        return -1;
    }
    return 0;
}
