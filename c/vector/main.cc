/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/14/2013 12:01:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>

using namespace std;

void ArrayPointer(int (*a)[5]) 
{
    cout << "[ArrayPointer]a:" << a << endl;
    cout << "[ArrayPointer]a+1:" << a + 1 << endl;
}

void PointerArray(int *a[5]) 
{
    cout << "[PointerArray]a:" << a << endl;
    cout << "[PointerArray]a+1:" << a + 1 << endl;
}

class Byte 
{
    unsigned char m_b;
};

int main(int argc, char *argv[]) 
{
    int array[10];

    cout << sizeof(array) << endl;
    cout << &array << endl;
    Byte *p = reinterpret_cast<Byte*>(&array[0]);
    cout << "array:" << array << endl;
    cout << "array + 1:" << array + 1 << endl;
    cout << "p:" << p << endl;
    printf("p:%p\n", p);
    cout << &array + 1 << endl;

    cout << "sizeof(Byte):" << sizeof(Byte) << endl;

    ArrayPointer(0);
    PointerArray(0);

    return 0;
}
