/*************************************************************************
	> File Name: 11string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 22时24分36秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
class String{
public:
    String(const char *str)
    {
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }
    ~String(void)
    {
        delete[] m_str;
        m_str = NULL;
    }
    String(const String &that)
    {
        m_str = new char[strlen(that.m_str) + 1];
        strcpy(m_str, that.m_str);
    }
    const char *c_str(void)const{
        return m_str;
    }
private:
    char *m_str;
};

int main()
{
    String s("hello");
    cout << s.c_str() << endl;
    String s2 = s;
    cout << s2.c_str() << endl;

    return 0;
}
