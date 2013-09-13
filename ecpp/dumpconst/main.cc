/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 04:49:45 PM
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
    Widget& test() {
        cout << "none const test() is called" << endl;
        return *this;
    }

    const Widget& test() const {
        cout << "const test() is called" << endl;
        return const_cast<Widget&>(*this).test();
    }
};

int main(int argc, char *argv[]) 
{
    const Widget w = Widget();
    w.test().test();
    return 0;
}
