// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  1-100
// 
//        Version:  1.0
//        Created:  05/13/2013 07:00:19 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

#include<include/tree.h>

typedef struct {
    TreeNode* pLeastNode;
    TreeNode* pGreatestNode;
} PairNodes;

/**
 * Convert a sub binary-search-tree into a sorted double-linked list
 * Input:   pNode - the head of the sub tree
 *          pPairNodes - pointer to PairNodes which stores the least 
 *          and greatest nodes
 **/
void ConvertNode(TreeNode* pNode, PairNodes* pPairNodes) 
{
    if (!pNode) {
        pPairNodes->pLeastNode = NULL;
        return;
    }

    PairNodes pair;

    // Convert the left sub-tree
    ConvertNode(pNode->m_pLeft, &pair);

    // Connect the greatest node in the left sub-tree to the current node
    if (pair.pLeastNode) {
        pair.pGreatestNode->m_pRight = pNode;
        pNode->m_pLeft = pair.pGreatestNode;
        // Store the least node of current sub-tree
        pPairNodes->pLeastNode = pair.pLeastNode;
    } else {
        // (pair.pLeastNode == NULL) ==> (pNode->m_pLeft == NULL), 
        // so we don't need to assign NULL to pNode->m_pLeft again

        // Store the least node of current sub-tree
        pPairNodes->pLeastNode = pNode;
    }

    // convert the right sub-tree
    ConvertNode(pNode->m_pRight, &pair);

    // Connect the greatest node in the left sub-tree to the current node
    if (pair.pLeastNode) {
        pair.pLeastNode->m_pLeft = pNode;
        pNode->m_pRight = pair.pLeastNode;

        // Store the greatest node of current sub-tree
        pPairNodes->pGreatestNode = pair.pGreatestNode;
    } else {
        // (pair.pLeastNode == NULL) ==> (pNode->m_pRight == NULL), so 
        // we don't need to assign NULL to pNode->m_pRight again

        // Store the least node of current sub-tree
        pPairNodes->pGreatestNode = pNode;
    }
}

/**
 * Convert a sub binary-search-tree into a sorted double-linked list
 * Input:   pTree -             the head of the sub tree
 *          pFirstNodeInList -  the head of the double-linked list
 **/
void ConvertNode2(TreeNode* pTree, TreeNode*& pFirstNodeInList) 
{
    if (!pTree) {
        return;
    }

    // Convert the right sub tree
    ConvertNode2(pTree->m_pRight, pFirstNodeInList);

    // Insert current node into the node list
    if (pFirstNodeInList) {
        pFirstNodeInList->m_pLeft = pTree;
        pTree->m_pRight = pFirstNodeInList;
    }

    // Now current node is the first node in the list
    pFirstNodeInList = pTree;

    // Convert the left sub tree
    ConvertNode2(pTree->m_pLeft, pFirstNodeInList);

}

TreeNode* ConvertSubTree1(TreeNode* pTree) 
{
    static TreeNode tree;
    PairNodes pair;

    ConvertNode(pTree, &pair);
    tree = *(pair.pLeastNode);

    return &tree;
}

TreeNode* ConvertSubTree2(TreeNode* pTree) 
{
    TreeNode* pFirstNode = NULL;

    ConvertNode2(pTree, pFirstNode);

    return pFirstNode;
}

int main(int argc, char* argv[]) 
{
    TreeNode* pTree = GenTree();

    TreeNode *p = ConvertSubTree2(pTree);

    std::cout << std::endl;
    for (; p; p = p->m_pRight) {
        std::cout << p->m_nValue << " ";
    }

    std::cout << std::endl;

    return 0;
}
