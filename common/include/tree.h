/*
 * =====================================================================================
 *
 *       Filename:  tree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 09:08:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#ifndef TREE_H
#define TREE_H
struct TreeNode 
{
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
};
TreeNode * GenTree();
void PrintPreOrder(TreeNode *root);
void PrintPostOrder(TreeNode *root);
#endif
