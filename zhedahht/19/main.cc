// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/10/2013 08:09:32 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

struct ListNode 
{
    int value;
    ListNode* next;
};

/**
 * Reverse a list iteratively
 * Input: head - the head of original list
 * Output: the head of reversed list
 **/
ListNode* ReverseList(ListNode& head) 
{
    ListNode* reversed_head = NULL;
    ListNode* node = head;
    ListNode* next = NULL;

    while (node) {
        next = node->next;
        node->next = reversed_head;

        reversed_head = node;
        node = node->next;
    }

    return reversed_head;
}
