// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/06/2013 07:46:53 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

struct ComplexNode 
{
    int value;
    ComplexNode* next;
    ComplexNode* sibling;
}

/**
 * Clone all nodes in a complex linked list with head head.
 * and connect all nodes with next_ link
 **/
void CloneNodes(ComplexNode* head) 
{
    ComplexNode* node = head;
    while (node) {
        ComplexNode* cloned = new ComplexNode();
        cloned->value = node->value;
        cloned->next = node->next;
        cloned->sibling = NULL;

        node->next = cloned;

        node = cloned->next;

    }
}

/**
 * Connect sibling nodes in a complex linked list
 **/
void ConnectSiblingNodes(ComplexNode* head) 
{
    ComplexNode* node = head;
    while (node) {
        ComplexNode* cloned = node->next;
        if (node->sibling) {
            cloned->sibling = node->sibling->next;
        }

        node = cloned->next;
    }
}

/**
 * Split a complex list into two:
 * the original list, and its cloned list
 **/
ComplexNode* ReconnectNodes(ComplexNode* head) 
{
    if (!head) {
        return NULL;
    }

    ComplexNode* node = head;
    ComplexNode* cloned_head = head->next;
    ComplexNode* cloned = cloned_head;
    node->next = cloned->next;
    node = node->next;
    
    while (node) {
        cloned->next = node->next;
        cloned = cloned->next;

        node->next = cloned->next;
        node = node->next;

        node = node->next;
    }

    return cloned_head;
}

/**
 * Clone a complex linked list with head head
 **/
ComplexNode* Clone(Complex* head) {
    CloneNodes(head);
    ConnectSiblingNodes(head);
    return ReconnectNodes(head);
}
