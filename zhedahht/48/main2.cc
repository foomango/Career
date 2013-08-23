/*
 * =====================================================================================
 *
 *       Filename:  main2.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201372385412876/
 *
 *        Version:  1.0
 *        Created:  08/23/2013 08:57:52 PM
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

bool GetNodePath(TreeNode *head, TreeNode *node, list<TreeNode*> &path) 
{
    if (head == node) {
        return true;
    }

    path.push_back(head);
    
    bool found = false;
    if (head->m_pLeft != NULL) {
        found = GetNodePath(head->m_pLeft, node, path);
    }
    
    if (!found && head->m_pRight != NULL) {
        found = GetNodePath(head->m_pRight, node, path);
    }

    if (!found) {
        path.pop_back();
    }

    return found;
}

TreeNode* LastCommonNode(list<TreeNode*> &path1, list<TreeNode*> &path2) 
{
    list<TreeNode*>::iterator iter1 = path1.begin();
    list<TreeNode*>::iterator iter2 = path2.begin();

    TreeNode *result = NULL;

    while (iter1 != path1.end() && iter2 != path2.end()) {
        if (*iter1 == *iter2) {
            result = *iter1;
        }
        else {
            break;
        }
        ++iter1;
        ++iter2;
    }

    return result;
}

TreeNode* LastCommonParent(TreeNode* head, TreeNode* tree1, TreeNode* tree2) 
{
    list<TreeNode*> path1;
    list<TreeNode*> path2;

    if (head == NULL || tree1 == NULL || tree2 == NULL) {
        return NULL;
    }

    GetNodePath(head, tree1, path1);
    GetNodePath(head, tree2, path2);

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

    TreeNode* last_common_parent = LastCommonParent(pHead, GetNodeFromValue(pHead, 200), GetNodeFromValue(pHead, 300));
    if (last_common_parent != NULL) {
        cout << last_common_parent->m_nValue << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    return 0;
}
