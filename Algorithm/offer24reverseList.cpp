#include <iostream>
//剑指 Offer 24. 反转链表
/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p0 = head;
        ListNode *p1;
        ListNode *p2;
        while (1)
        {
            if (p0 == head)
            {
                p1 = p0->next;
                p2 = p1->next;
                p0->next = NULL;
            }
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            if(p1==NULL)
                return p0;
            p2 = p1->next;
        }
        return p0;
    }
};

int main()
{
    return 0;
}
