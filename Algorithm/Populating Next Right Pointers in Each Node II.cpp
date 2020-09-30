#include <iostream>
#include <queue>
using std::queue;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//可以使用本身形成的next结点来遍历每一层，只需保留每层的最左侧的节点的左节点作为起点即可

class Solution
{
    queue<Node *> q;
    queue<Node *> p;

public:
    Node *connect(Node *root)
    {
        Node *tmp;
        q.push(root);
        while (!q.empty() || !p.empty())
        {
            while (!q.empty())
            {
                tmp = q.front();
                q.pop();
                if (q.empty())
                    tmp->next = NULL;
                else
                    tmp->next = q.front();
                if (tmp->left != NULL)
                    p.push(tmp->left);
                if (tmp->right != NULL)
                    p.push(tmp->right);
            }
            while (!p.empty())
            {
                tmp = p.front();
                p.pop();
                if (p.empty())
                    tmp->next = NULL;
                else
                    tmp->next = p.front();
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
            }
        }
        return root;
    }
};

int main(){

    return 0;
}