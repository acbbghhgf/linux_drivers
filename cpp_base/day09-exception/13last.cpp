/*************************************************************************
	> File Name: 13last.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 10时55分33秒
 ************************************************************************/
#include <fstream>
#include<iostream>
using namespace std;

int main()
{
    ofstream ofs("last.txt");
    char wbuf[] = "C++ 流格式化";
    ofs.write(wbuf, sizeof(wbuf));
    ofs.close();

    ifstream ifs("last.txt");
    char rbuf[50] = {0};
    ifs.read(rbuf, sizeof(rbuf));
    cout << "读到的数据：" << rbuf << endl;
    ifs.close();

    return 0;
}

