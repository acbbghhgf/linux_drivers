/*************************************************************************
	> File Name: shape.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 20时31分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Shape{
public:
    Shape(int x=0, int y = 0):m_x(x),m_y(y){}
    virtual void draw(void)
    {
        cout << "绘制图形：" << m_x << ',' << m_y << endl;
    }
protected:
    int m_x;
    int m_y;
};

class Rect:public Shape{
public:
    Rect(int x, int y, int w, int h):Shape(x, y),m_w(w),m_h(h){}
    void draw(void)
    {
        cout << "绘制矩形:" << m_x << ',' << m_y << ',' << m_w << "," << m_h << endl;
    }
private:
    int m_w;
    int m_h;
};

class Circle:public Shape{
public:
    Circle(int x, int y, int r):Shape(x, y),m_r(r){}
    void draw(void)
    {
        cout << "绘制圆形：" << m_x << "," << m_y << "," << m_r << endl;
    }
private:
    int m_r;
};

void render(Shape *buf[])
{
    for(int i = 0; buf[i] != NULL; i++)
    {
        buf[i]->draw();
    }
}

int main()
{
    Shape *buf[1024] = {NULL};
    
    buf[0] = new Rect(1,2,3,4);
    buf[1] = new Rect(11,21,33,24);
    buf[2] = new Circle(5,7,8);
    buf[3] = new Rect(1,2,3,4);
    buf[4] = new Circle(9,10,13);
    buf[5] = new Rect(1,2,3,4);

    render(buf);

    return 0;
}
