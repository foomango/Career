/*
 * =====================================================================================
 *
 *       Filename:  6.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2013 07:48:23 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

class FirstClass {
    public:
        virtual void MethodA(int i);
        virtual void MethodA(int i, int j);
};

void FirstClass::MethodA(int i) {
    std::cout << "One.\n";
}

void FirstClass::MethodA(int i, int j) {
    std::cout << "Two.\n";
}

class SecondClass : public FirstClass {
    public:
        void MethodA(int i);
        //void MethodA(int i, int j);
};

void SecondClass::MethodA(int i) {
    std::cout << "Three.\n";
}

/*void SecondClass::MethodA(int i, int j) {
    std::cout << "Four.\n";
}*/

int main(int argc, char *argv[]) {
    SecondClass a;
    a.MethodA(1);
    a.MethodA(1, 1);
}
