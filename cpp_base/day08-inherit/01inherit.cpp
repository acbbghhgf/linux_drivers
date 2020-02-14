/*************************************************************************
	> File Name: 01inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 10时24分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Human{
public:
    Human(const string& name, int age):m_name(name),m_age(age),m_id(123){}
    void eat(const string &food)
    {
        cout << "我在吃" << food << endl;
    }
    void sleep(int hour)
    {
        cout << "我睡了" << hour << "小时" << endl;
    }
protected:
    string m_name;
    int m_age;
public:
    const int &getId(void)const{
        return m_id;
    }
private:
    int m_id;
};

class Student:public Human{
public:
    Student(const string &name, int age, int no):Human(name, age),m_no(no){}
    void learn(const string &course)
    {
        cout << "我在学" << course << endl;
    }
    void who(void)
    {
        cout << "我叫" << m_name << ", 今年" << m_age << "岁，学号是" << m_no << endl;
        cout << "身份证号：" << getId() << endl;
    }
private:
    int m_no;
};

class Teacher:public Human{
public:
    Teacher(const string &name, int age, int salary):Human(name, age),m_salary(salary){}
    void teach(const string &course)
    {
        cout << "我在讲" << course << endl;
    }
    void who(void)
    {
        cout << "我叫" << m_name << ",今年" << m_age << "岁， 工资是" << m_salary << endl;
        cout << "身份证号:" << getId() << endl;
    }
private:
    int m_salary;
};

int main()
{
    Student s("关羽", 29, 10011);
    s.who();
    s.eat("红烧牛肉面");
    s.sleep(8);
    s.learn("孙武兵法");

    Teacher t("悟空", 30, 50000);
    t.who();
    t.eat("水蜜桃");
    t.sleep(6);
    t.teach("Unix C编程");

    Human *ph = &s;
    ph->eat("平谷大桃");
    ph->sleep(2);

    Student *ps = static_cast<Student *>(ph);
    ps->who();

    Human h("林黛玉", 28);
    Student *ps2 = static_cast<Student *>(&h);
    ps2->who();

    return 0;
}
