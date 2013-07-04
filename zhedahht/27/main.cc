/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 01:05:39 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

#include <include/tree.h>

int TreeDepth(TreeNode *pTreeNode) 
{
    if (!pTreeNode) {
        return 0;
    }

    int nLeft = TreeDepth(pTreeNode->m_pLeft);
    int nRight = TreeDepth(pTreeNode->m_pRight);

    return (nLeft > nRight ) ? (nLeft + 1) : (nRight + 1);
}

int main(int argc, char *argv[]) 
{
    TreeNode *pTree = GenTree();
    if (!pTree) {
        std::cout << "no memory" << std::endl;
        return -1;
    }

    std::cout << TreeDepth(pTree) << std::endl;

    return 0;
}
