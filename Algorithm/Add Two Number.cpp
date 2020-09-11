#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//总结一下犯的错误：
//1、进位计算错误
//2、l1->next 为null时忘记处理当前节点的值
//3、if逻辑比较混乱，没有使用else if/else结尾导致函数跳出后继续执行产生错误
//4、链表情况分析差错较多，思路一开始不是很清楚
//5、不记得将最尾部carry == 0的情况区分，导致多产生一个最开始的val==0的链表节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void addOneByOne(ListNode *l1, ListNode *l2, int carry)
    {
        if (l2 == NULL)
        {
            if (carry == 0)
                return;
            if (l1->next == NULL)
            {
                l1->val += carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                if (carry != 0)
                    l1->next = new ListNode(carry);
                return;
            }
            else
            {
                l1->val += carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                addOneByOne(l1->next, NULL, carry);
            }
        }
        else if (l1->next == NULL && l2->next == NULL)
        {
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val = l1->val % 10;
            if (carry != 0)
                l1->next = new ListNode(carry);
            return;
        }
        else if (l1->next == NULL || l2->next == NULL)
        {
            if (l1->next == NULL)
            {
                l1->val = l1->val + l2->val + carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                l1->next = l2->next;
                addOneByOne(l1->next, NULL, carry);
            }
            else
            {
                l1->val = l1->val + l2->val + carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                addOneByOne(l1->next, NULL, carry);
            }
        }
        else
        {
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val = l1->val % 10;
            addOneByOne(l1->next, l2->next, carry);
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        addOneByOne(l1, l2, 0);
        return l1;
    }
};