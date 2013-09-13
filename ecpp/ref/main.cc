/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/2013 04:14:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Widget {
public: 
    Widget() { 
        m_n = 1;
        cout << "constructor is called" << endl;
    }

    ~Widget() {
        m_n = 0;
        cout << "destructor is called" << endl;
    }

    static Widget getInstance() {
        Widget w;
        return w;
    }

    void print() {
        cout << "n:" << m_n << endl;;
    }

private:
    int m_n;
};

int main(int argc, char *argv[]) 
{

    cout << "before" << endl;
    Widget w = Widget::getInstance();
    cout << "after" << endl;

    w.print();

    cout << "print done" << endl;

    cout << &w << endl;
    return 0;
}
