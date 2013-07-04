// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/10/2013 07:26:29 PM
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
}

/**
 * Delete a node in a list
 * Input: head - the head of the list
 *        to_be_deleted - the node to be deleted
 * Return: the head of the list which has delete <code>to_be_deleted</code>
 **/
ListNode* Deleted(ListNode* head, ListNode* to_be_deleted) 
{
    // Invalid input
    if (!head || !to_be_deleted) {
        return head;
    }

    // to_be_deleted is not the last node
    if (to_be_deleted->next) {
        // Copy data from the next node to the to_be_deletede node
        ListNode* next = to_be_deleted->next;
        to_be_deleted->value = next->value;
        to_be_deleted->next = next->next;

        // Delete the next node
        delete next;
        next = NULL;
    } else {
        // The list only has one node, and it will be deleted
        if (head == to_be_deleted) {
            delete head;
            return NULL;
        }
        // Get the node prior to be
        ListNode* prior_node = head;
        while (prior_node->next != to_be_deleted) {
            prior_node = prior_node->next;
            assert(prior_node != NULL);
        }

        prior_node->next = NULL;
        delete to_be_deleted;
        to_be_deleted = NULL;
        return head;
    }

}
