// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/10/2013 06:55:26 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

struct ListLenth
{
    int value;
    ListLenth* next;
}

/**
 * Get the length of list with head <code>head</code>
 * Input: head - the head of list
 * Return: the length of list
 **/
int ListLength(ListNode* head) 
{
    int length = 0;
    ListNode* node = head;

    while (node) {
        length++;
        node = node->next;
    }

    return length;
}

/**
 * Find the first common node in the list with head <code>head1</code> and the list with 
 * head <code>head2</code>
 * Input: head1 - the head of the first list
 *        head2 - the head of the second list
 * Return: the first common node in two list. If there is no common nodes, return NULL
 **/
ListNode* FindFirstCommonNode(NodeList* head1, NodeList* head2) {
    if (!head1 || !head2) {
        return NULL;
    }

    // Get the length of two lists
    int length1 = ListLength(head1);
    int length2 = ListLength(head2);
    
    // Get the longer list
    ListNode* node_long = head1;
    ListNode* node_short = head2;
    int length_diff = length1 - length2;

    if (length1 < lengh2) {
        node_long = head2;
        node_short = head1;
        length_diff = length2 - length1;
    }

    // Move on the longer list
    for (int i = 0; i < length_diff; i++) {
        node_long = node_long->next;
    }

    // Move on both list
    while (node_long &&
            node_long != node_short) {
        node_long = node_long->next;
        node_short = node_short->next;
    }

    return node_long;
}
