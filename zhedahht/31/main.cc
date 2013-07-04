// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/10/2013 07:58:31 PM
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
 * Print a list from end to beginning
 * Input: head - the head of list, can not be NULL
 **/
void PrintListReverselyCore(ListNode* head) 
{
    // Print the next list first
    if (head->next) {
        PrintListReverseleyCore(head->next);
    }

    // Print the current node
    printf("%d ", head->value);
}

/**
 * Print a list from end to beginning
 * Input: head - the head of list
 **/
void PrintListReversely(ListNode* head) 
{
    if (!head) 
        return;

    PrintListReversely(head);
}
