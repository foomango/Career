/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/28/2013 07:38:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <list>

#include <include/tree.h>

using namespace std;

// Get the path from pHead to pNode in a tree with head pHead
bool GetNodePath(TreeNode* pHead, TreeNode* pNode, list<TreeNode*>& path) 
{
    if (pHead == pNode) {
        path.push_back(pHead);
        return true;
    }

    path.push_back(pHead);

    bool found = false;
    if (pHead->m_pLeft != NULL) 
        found = GetNodePath(pHead->m_pLeft, pNode, path);
    if (!found && pHead->m_pRight) 
        found = GetNodePath(pHead->m_pRight, pNode, path);

    if (!found) 
        path.pop_back();

    return found;
}

// Get the last common Node in two lists: path1 and path2
TreeNode* LastCommonNode(const list<TreeNode*>& path1, 
        const list<TreeNode*>& path2) 
{
    list<TreeNode*>::const_iterator iterator1 = path1.begin();
    list<TreeNode*>::const_iterator iterator2 = path2.begin();

    while (iterator1 != path1.end() && iterator2 != path2.end()) {
        if (*iterator1 != *iterator2) {
            return *(--iterator1);
        }

        iterator1++;
        iterator2++;
    }

    return NULL;
}

// Find the last parent of pNode1 and pNode2 in a tree with head pHead
TreeNode* LastCommonParent(TreeNode* pHead, TreeNode* pNode1, TreeNode* pNode2) 
{
    if (!pHead || !pNode1 || !pNode2) {
        return NULL;
    }

    list<TreeNode*> path1;
    GetNodePath(pHead, pNode1, path1);

    list<TreeNode*> path2;
    GetNodePath(pHead, pNode2, path2);

    return LastCommonNode(path1, path2);

}

TreeNode* GetNodeFromValue(TreeNode* pHead, int value) 
{
    if (!pHead) {
        return NULL;
    }

    if (pHead->m_nValue == value) {
        return pHead;
    }

    TreeNode* result = NULL;
    if (pHead->m_pLeft) {
        result = GetNodeFromValue(pHead->m_pLeft, value);
    }
    if (!result && pHead->m_pRight) {
        result = GetNodeFromValue(pHead->m_pRight, value);
    }

    return result;
}

int main(int argc, char *argv[]) 
{
    TreeNode* pHead = GenTree();
    if (!pHead) {
        return -1;
    }

    cout << LastCommonParent(pHead, GetNodeFromValue(pHead, 200), GetNodeFromValue(pHead, 300))->m_nValue << endl;
    return 0;
}
