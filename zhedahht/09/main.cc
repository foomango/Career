// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/10/2013 08:30:40 PM
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
 * Find the kth node from the tail of list
 * Input: head - the head of list
 *        k - the distance to the tail
 * Output: the kth node from the tail of list
 **/
ListNode* FindKthToTail(ListNode* head, int k) 
{
    if (!head) {
        return NULL;
    }

    ListNode* ahead_node = head;
    ListNode* behind_node = head;

    for (int i = 0; i < k + 1; i++) {
        if (!ahead_node) {
            return NULL;
        }
        ahead_node = ahead_node->next;
    }

    // The distance between ahead_node and behind_node is k + 1
    // when ahead_node is NULL, behind_node is at the kth node 
    // from the tail
    while (ahead_node) {
        ahead_node = ahead_node->next;
        behind_node = behind_node->next;
    }

    return behind_node;
}
