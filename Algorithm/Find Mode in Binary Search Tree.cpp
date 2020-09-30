#include <iostream>
#include <vector>
using std::vector;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//一道简单题，但是要把它优化到极致并不是十分简单的事
//为了不使用额外的空间，需要利用二叉搜索树的中序遍历的特点，再使用一个靠迭代的moris中序遍历，又节省了栈的开销
//因为中序遍历后相同的元素只会在一起出现，所以统计众数也就无需哈希表了。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
    int count = 0;
    int maxcount = 0;
    int cur;

public:
    void update(int val, vector<int> &ans)
    {
        if (val == cur)
        {
            count++;
        }
        else
        {
            cur = val;
            count = 1;
        }
        if (maxcount == count)
        {
            ans.push_back(val);
        }
        else if (maxcount < count)
        {
            ans.clear();
            ans.push_back(val);
            maxcount = count;
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ans{};
        if(root == NULL){
            return ans;
        }
        cur = root->val;
        TreeNode *temp = NULL;
        while (root != NULL)
        {
            if (root->left == NULL)
            {
                update(root->val, ans);
                root = root->right;
            }
            else
            {
                temp = root->left;
                while (temp->right != NULL && temp->right != root)
                {
                    temp = temp->right;
                }
                if (temp->right == NULL)
                {
                    temp->right = root;
                    root = root->left;
                }
                else
                {
                    update(root->val, ans);
                    temp->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};