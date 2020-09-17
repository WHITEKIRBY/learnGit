#include <iostream>
#include <queue>
#include <deque>
using std::deque;
using std::queue;
//本题应使用双端队列，维护一个递减队列和一个正常序队列即可。
//使用链表的方法实现要实现求最大值的话，维护两条链表肯定比维护队列要困难的多。

// class MaxQueue
// {
// public:
//     struct Node
//     {
//         int ele;
//         Node *Next;
//         Node(int x) : ele(x), Next(NULL){};
//     };
//     Node *rear;
//     Node *Head;
//     Node *max_value;
//     MaxQueue()
//     {
//         Head = new Node(-1);
//         max_value = rear = Head;
//     }
//     int max_value()
//     {
//         return max_value->ele;
//     }
//     void push_back(int value)
//     {
//         rear->Next = new Node(value);
//         rear = rear->Next;
//         if (max_value->ele < rear->ele)
//         {
//             max_value->Next = max_value;
//             max_value = rear;
//         }
//         else
//         {
//             max_value->Next = rear;
//         }
//     }
//     int pop_front()
//     {
//         int ans;
//         if (rear == Head)
//         {
//             return -1;
//         }
//         else
//         {
//             Node *tmp;
//             tmp = Head->Next;
//             ans = tmp->ele;
//             Head->Next = Head->Next->Next;
//             if (rear == tmp)
//                 rear = Head;
//             if (Head->ele == tmp->ele)
//                 Head->ele = tmp->Next->ele;
//             delete tmp;
//         }
//         return ans;
//     }
// };

class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。