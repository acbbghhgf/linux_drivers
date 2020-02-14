/*************************************************************************
	> File Name: mul_inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 19时42分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Phone{
public:
    Phone(const string &number):m_number(number){}
    void call(const string &number)
    {
        cout << m_number << "打电话给" << number << endl;
    }
private:
    string m_number;
};

class Player{
public:
    Player(const string &media):m_media(media){}
    void play(const string &music)
    {
        cout << m_media << "播放器播放" << music << endl;
    }
private:
    string m_media;
};

class Computer{
public:
    Computer(const string &os):m_os(os){}
    void run(const string &app)
    {
        cout << "在" << m_os << "系统上运行" << app << endl;
    }
private:
    string m_os;
};

class SmartPhone: public Phone, public Player, public Computer
{
public:
    SmartPhone(const string &number, const string &media, const string &os):Phone(number),Player(media),Computer(os){}
};

int main()
{
    SmartPhone iphoneX("13866668888", "MP4", "Android");

    iphoneX.call("010-110");
    iphoneX.play("最炫小苹果.mp3");
    iphoneX.run("Angry Brid");

    SmartPhone *p1 = &iphoneX;
    Phone *p2 = p1;
    Player *p3 = p1;
    Computer *p4 = p1;

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;

    return 0;
}
