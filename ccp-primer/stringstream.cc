/*
 * =====================================================================================
 *
 *       Filename:  stringstream.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2013 07:14:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <sstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostringstream;
using std::istringstream;
using std::string;

void Test() 
{
    int val1 = 512;
    int val2 = 1024;
    ostringstream format_message;

    format_message << "val1: " << val1 << "\n" 
        << "val2: " << val2 << "\n";

    istringstream input_istream(format_message.str());
    string label1;
    string label2;
    input_istream >> label1 >> val1 >> label2 >> val2;
    // "val1: "
    cout << label1 << endl;
    // "val2: "
    cout << label2 << endl;
    // "512"
    cout << val1 << endl;
    // "1024"
    cout << val2 << endl;
}

int main(int argc, char* argv[]) 
{
    Test();
    return 0;
}
