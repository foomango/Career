/*
 * =====================================================================================
 *
 *       Filename:  main2.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/21809807420137237340518/
 *
 *        Version:  1.0
 *        Created:  08/23/2013 07:54:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

struct ComplexNode {
    int value;
    struct ComplexNode *next;
    struct ComplexNode *sibling;
};

struct ComplexNode* CloneNodes(ComplexNode *head) 
{
    struct ComplexNode *p = head;
    struct ComplexNode *q = NULL;
    while (p != NULL) {
        q = malloc(sizeof(struct ComplexNode));
        if (q == NULL) {
            return NULL;
        }
        q->value = p->value;
        q->next = p->next;
        q->slibling = NULL;
        p->next = q;
        p = q->next;
    }

    return head;
}

void ConnectSiblingNodes(ComplexNode *head) 
{
    struct ComplexNode *p = head;

    while (p != NULL) {
        if (p->sibling != NULL) {
            p->next->sibling = p->sibling-next;
        }
        p = p->next->next;
    }
}

ComplexNode* ReconnectNodes(ComplexNode *head) 
{
    struct ComplexNode *p = head;
    struct ComplexNode *q = NULL;
    struct ComplexNode *clone = NULL;

    if (head != NULL) {
        clone = head->next;
        q = clone;

        p->next = q->next;
        p = p->next;;
    }

    while (p != NULL) {
        q->next = p->next;
        q = q->next;
        
        p->next = q->next;
        p = p->next;
    }

    return clone;
}

ComplexNode* Clone(ComplexNode *head) 
{
    if (CloneNodes(head) == NULL) {
        return -1;
    }

    ConnectSiblingNodes(head);
    return ReconnectNodes(head);
}
