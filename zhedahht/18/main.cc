// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/15/2013 07:30:22 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <string>

#include <CQueue.h>

int main(int argc, char* argv[]) 
{
    CQueue<std::string> queue;

    queue.appendTail("a");
    queue.appendTail("b");
    queue.appendTail("c");
    queue.deleteHead();
    queue.deleteHead();
    queue.appendTail("d");
    queue.deleteHead();
    queue.deleteHead();

    return 0;
}
