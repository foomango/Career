/*
 * =====================================================================================
 *
 *       Filename:  main2.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201372282057117/
 *
 *        Version:  1.0
 *        Created:  08/22/2013 08:34:19 PM
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

using std::cout;
using std::endl;

/*
 * 判断从tree1的根节点开始，是否完全包含tree2
 * Input: 
 *  tree1 - tree1的根节点
 *  tree2 - tree2的根节点
 * Output: 
 *  如果从tree1的根节点开始，完全包含tree2，则返回true，否则返回false
 */
bool DoesTree1HaveAllNodesOfTree2(TreeNode *tree1, TreeNode *tree2) 
{
    if (tree2 == NULL) {
        return true;
    }

    if (tree2 == NULL) {
        return false;
    }

    if (tree1->m_nValue != tree2->m_nValue) {
        return false;
    }

    return DoesTree1HaveAllNodesOfTree2(tree1->m_pLeft, tree2->m_pLeft) && 
        DoesTree1HaveAllNodesOfTree2(tree1->m_pRight, tree2->m_pRight);
}

/*
 * 判断tree2是否为tree1的子树
 * Input: 
 *  tree1 - tree1的根节点
 *  tree2 - tree2的根节点
 * Output: 
 *  如果tree2是tree1的子树，则返回true，否则返回false
 */
bool HasSubtree(TreeNode *tree1, TreeNode *tree2) 
{
    bool result = false;

    if (tree1 == NULL) {
        return false;
    }

    result = DoesTree1HaveAllNodesOfTree2(tree1, tree2);

    if (!result) {
        result = HasSubtree(tree1->m_pLeft, tree2);
    }

    if (!result) {
        result = HasSubtree(tree1->m_pRight, tree2);
    }

    return result;
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
