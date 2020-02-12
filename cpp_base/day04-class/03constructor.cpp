/*************************************************************************
	> File Name: 01constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 08时39分10秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Student{
public:
    Student(const string &name, int age, int no)
    {
        cout << "constructor func "<< endl;
        m_name = name;
        m_age = age;
        m_no = no;
    }
    void who(void)
    {
        cout << "my name is " << m_name << ", this year is " << m_age << ", id is " << m_no << endl;
    }

private:
    string m_name;
    int m_age;
    int m_no;
};

int main()
{
    Student s = Student("李辉", 35, 10011);
    s.who();

    Student sarr[3] = {
        Student("白骨精", 19, 10012),
        Student("林黛玉", 18, 10013),
        Student("潘金莲", 20, 10014)
    };

    sarr[0].who();
    sarr[1].who();
    sarr[2].who();

    Student *ps = new Student("貂蝉", 17, 10015);
    ps->who();
    delete ps;
    ps = NULL;

    Student *parr = new Student[3]{
        Student("小乔", 29, 10016),
        Student("大乔", 28, 10017),
        Student("西施", 30, 10018)
    };
    parr[0].who();
    parr[1].who();
    parr[2].who();
    delete[] parr;
    parr = NULL;

    return 0;
}
