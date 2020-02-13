/*************************************************************************
	> File Name: 05this.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 21时34分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Student;
class Teacher{
public:
    void educate(Student *s);
    void reply(const string &answer);
private:
    string m_answer;
};

class Student{
public:
    void ask(const string &question, Teacher *t);
};

void Teacher::educate(Student *s)
{
    s->ask("什么是this指针？", this);
    cout << "学生回答：" << m_answer << endl;
}

void Teacher::reply(const string &answer)
{
    m_answer = answer;
}

void Student::ask(const string &question, Teacher *t)
{
    cout << "question : " << question << endl;
    t->reply("this指针指向调用对象的地址");
}

int main()
{
    Teacher teacher;
    Student student;
    teacher.educate(&student);
    return 0;
}


