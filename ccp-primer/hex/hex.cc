/*
 * =====================================================================================
 *
 *       Filename:  hex.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2013 11:16:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) 
{
    int *p = reinterpret_cast<int*>(32);
    ostringstream oss;
    oss << "test1";
    cout << oss.str() << endl;
    cout << hex << static_cast<void*>(p) << endl;

    return 0;
}
