/*
 * =====================================================================================
 *
 *       Filename:  tree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 09:03:58 PM
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

TreeNode * GenTree() 
{
    TreeNode * root = NULL;
    int data;

    cin >> data;
    if (data == -1) {
        root = NULL;
    } else {
        root = new TreeNode;
        root -> m_nValue = data;
        root -> m_pLeft = GenTree();
        root -> m_pRight = GenTree();
    }

    return root;

}

void PrintPreOrder(TreeNode *root) 
{
    if (root != NULL) {
        cout << root -> m_nValue << " ";
        PrintPreOrder(root -> m_pLeft);
        PrintPreOrder(root -> m_pRight);
    }
}

void PrintPostOrder(TreeNode *root) 
{
    if (root != NULL) {
        PrintPostOrder(root -> m_pLeft);
        PrintPostOrder(root -> m_pRight);
        cout << root -> m_nValue << " ";
    }
}
