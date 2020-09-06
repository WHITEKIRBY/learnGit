#include <iostream>
#include <vector>
#include <array>
#include<algorithm>
using namespace std;
//二叉树的层次遍历

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res{};
        if (root == NULL)
            return res;
        vector<TreeNode *> stack{root};
        vector<TreeNode *> temp{};
        vector<int> res_each{};

        while (stack.empty() == false)
        {
            for (auto i : stack)
            {
                res_each.insert(res_each.begin(), i->val);
                if (i->right != NULL)
                    temp.push_back(i->right);
                if (i->left != NULL)
                    temp.push_back(i->left);
            }
            stack = move(temp);
            res.emplace(res.end(), move(res_each));//Tip:这里不能在头部插入，否则移动元素带来的时间开销极大！
        }
        reverse(res.begin(),res.end());
        return res;
    }
};