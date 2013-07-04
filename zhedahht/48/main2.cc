// =====================================================================================
// 
//       Filename:  main2.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/06/2013 09:45:55 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

#include <include/tree.h>

/**
 * Get the path from pHead to pNode in a tree with head pHead
 **/
bool GetNodePath(TreeNode *pHead, TreeNode *pNode, std::list<TreeNode *>& path) 
{
    if (pHead == pNode) {
        return true;
    }

    bool result = false;
    path.push_back(pHead);
    if (!pNode->m_pLeft) {
        result = GetNodePath(pHead->m_pLeft, pNode, path);
    }
    if (!result && pNode->m_pRight) {
        result = GetNodePath(pHead->m_pRight, pNode, path);
    }
    if (!result) {
        path.pop_back(pHead);
    }

    return result;
}

/**
 * Get the last common Node in two lists: path1 and path2
 **/
TreeNode* LastCommonNode(
        const std::list<TreeNode *>& path1, 
        const std::list<TreeNode *>& path2)
{
    std::list<TreeNode *>::const_iterator iterator1 = path1.begin();
    std::list<TreeNode *>::const_iterator iterator2 = path2.begin();

    TreeNode* pLast = NULL;

    while (iterator1 != path1.end() && iterator2 != path2.end()) {
        if (*iterator1 != *iterator2) {
            break;
        } else {
            pLast = *iterator1;
            iterator1++;
            iterator2++;
        }
    }

    return pLast;
}
