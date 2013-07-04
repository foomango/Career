/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 08:49:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <include/tree.h>
using namespace std;

bool DoesTree1HaveAllNodesOfTree2(TreeNode* pTreeHead1, TreeNode* pTreeHead2);

bool HasSubtreeCore(TreeNode* pTreeHead1, TreeNode* pTreeHead2) 
{
    bool result = false;

    if (pTreeHead1->m_nValue == pTreeHead2->m_nValue) {
        result = DoesTree1HaveAllNodesOfTree2(pTreeHead1, pTreeHead2);
    }

    if (!result && pTreeHead1->m_pLeft != NULL) {
        result = HasSubtreeCore(pTreeHead1->m_pLeft, pTreeHead2);
    }

    if (!result && pTreeHead1->m_pRight != NULL) {
        result = HasSubtreeCore(pTreeHead1->m_pRight, pTreeHead2);
    }

    return result;
}

bool DoesTree1HaveAllNodesOfTree2(TreeNode* pTreeHead1, TreeNode* pTreeHead2) 
{
    if (pTreeHead2 == NULL) {
        return true;
    }

    if (pTreeHead1 == NULL) {
        return false;
    }

    if (pTreeHead1->m_nValue != pTreeHead2->m_nValue) {
        return false;
    }

    return DoesTree1HaveAllNodesOfTree2(pTreeHead1->m_pLeft, pTreeHead2->m_pLeft) && 
        DoesTree1HaveAllNodesOfTree2(pTreeHead1->m_pRight, pTreeHead2->m_pRight);
}

bool HasSubtree(TreeNode* pTreeHead1, TreeNode* pTreeHead2) 
{
    if (pTreeHead2 == NULL) {
        return true;
    }

    if (pTreeHead1 == NULL) {
        return false;
    }

    return HasSubtreeCore(pTreeHead1, pTreeHead2);
}

int main(int argc, char *argv[]) 
{
    TreeNode *pTreeHead1 = GenTree();
    TreeNode *pTreeHead2 = GenTree();

    cout << "Tree1: " << endl;
    PrintPreOrder(pTreeHead1);
    cout << endl;
    PrintPostOrder(pTreeHead1);
    cout << endl << "Tree2: " << endl;
    PrintPreOrder(pTreeHead2);
    cout << endl;
    PrintPostOrder(pTreeHead2);
    cout << endl;

    cout << HasSubtree(pTreeHead1, pTreeHead2) << endl;

    return 0;

}
