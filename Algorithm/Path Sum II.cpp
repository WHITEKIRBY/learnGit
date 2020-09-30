#include <iostream>
#include <vector>
using std::vector;

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
    void dfs(TreeNode *root, vector<vector<int>> &ans, vector<int> combine, int sum)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            // if (sum <= 0)
            //     return;
            //题目没保证输入二叉树和sum的值一定为正数！
            sum -= root->val;
            combine.push_back(root->val);
            if (sum == 0 && root->left == NULL && root->right == NULL)
            {
                ans.push_back(combine);
                return;
            }
            else
            {
                dfs(root->left, ans, combine, sum);
                dfs(root->right, ans, combine, sum);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ans{};
        vector<int> combine{};
        dfs(root, ans, combine, sum);
        return ans;
    }
};