/*************************************************************************
	> File Name: 02clock.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 08时44分31秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>

using namespace std;

class Clock{
public:
    Clock(time_t t)
    {
        tm *local = localtime(&t);
        m_hour = local->tm_hour;
        m_min = local->tm_min;
        m_sec = local->tm_sec;
    }
    void run(void)
    {
        while(1){
            printf("\r%02d:%02d:%02d", m_hour, m_min, m_sec);
            fflush(stdout);
            if(++m_sec == 60)
            {
                m_sec = 0;
                if(++m_min == 60)
                {
                    m_min = 0;
                    if(++m_hour == 24)
                    {
                        m_hour = 0;
                    }
                }
            }
            sleep(1);
        }
    }
private:
    int m_hour;
    int m_min;
    int m_sec;
};

int main()
{
    Clock c(time(0));
    c.run();
    return 0;
}

