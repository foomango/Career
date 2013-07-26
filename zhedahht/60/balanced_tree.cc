/*
 * =====================================================================================
 *
 *       Filename:  balanced_tree.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/21809807420136269224499/
 *
 *        Version:  1.0
 *        Created:  07/26/2013 09:01:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

bool IsBalancedBiTree(BiTreeNode* root, int& depth) 
{
    if (root == NULL) {
        depth = 0;
        return true;
    }

    int left_depth = 0;
    int right_depth = 0;
    if (IsBalancedBiTree(root->left, left_depth) && IsBalancedBiTree(root->right, right_depth)) {
        int diff
    }
}
