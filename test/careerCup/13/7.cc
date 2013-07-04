/*
 * =====================================================================================
 *
 *       Filename:  7.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2013 08:04:30 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

class Base {
    public:
        Base() { cout << "Base Constructor " << endl; }
        ~Base() { cout << "Base Destructor " << endl; }
};

class Derived : public Base {
    public:
        Derived() { cout << "Derived Constructor " << endl; }
        ~Derived() { cout << "Derived Destructor " << endl; }
};

int main (int argc, char *argv[]) {
    Base *p = new Derived();
    delete p;
}
