/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <queue>
#include <vector>
using std::queue;
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> sum{};
        vector<int> count{};
        dfs(root, 0, sum, count);
        for(int i = 0;i<sum.size();i++)
        {
            sum[i] = sum[i]/count[i];
        }
        return sum;
    }
    void dfs(TreeNode *root, int level, vector<double> &sum, vector<int> &count)
    {
        if (root == NULL)
            return;
        if (level < sum.size())
        {
            sum[level] += root->val;
            count[level]++;
        }
        else
        {
            sum.push_back(root->val);
            count.push_back(1);
        }
        dfs(root->left, level + 1, sum, count);
        dfs(root->right, level + 1, sum, count);
    };
};