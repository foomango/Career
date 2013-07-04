/*
 * =====================================================================================
 *
 *       Filename:  test_gentree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 09:21:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <include/tree.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{
    TreeNode *root = GenTree();
    cout << "PreOrder: ";
    PrintPreOrder(root);
    cout << endl;
    cout << "PostOrder: ";
    PrintPostOrder(root);
    cout << endl;
    return 0;
}
