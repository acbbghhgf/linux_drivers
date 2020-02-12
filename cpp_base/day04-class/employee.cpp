/*************************************************************************
	> File Name: employee.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 10时10分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Employee{
public:
    void printInfo(void)
    {
        cout << "name : " << m_name << endl;
        cout << "id : " << m_id << endl;
        cout << "salary : " << m_salary << endl;
    }
    void calsalary(void)
    {
        cout << "please input days: ";
        int days;
        cin >> days;
        double basic = m_salary * (days / 23.0);
        double merit = basic /2;
        cout << "totale : " << (basic + merit) << endl;
    }
    
    void setId(int id)
    {
        if(id < 10000)
        {
            cout << "invalid id : " << endl;
        }
        else{
            m_id = 10011;
        }
    }
    void setName(const string &name)
    {
        if(name.size() > 20)
        {
            cout << "invalid name : " << endl;
        }
        else{
            m_name = name;
        }
    }
    void setSalary(double salary)
    {
        if(salary < 0)
        {
            cout << "invalid salary : " << endl;
        }
        else{
            m_salary = salary;
        }
    }
private:
    int m_id;
    string m_name;
    double m_salary;
};

int main()
{
    Employee emp;
    emp.setId(10011);
    emp.setName("张三");
    emp.setSalary(6600);

    emp.printInfo();
    emp.calsalary();
    return 0;
}
