#include <iostream>
#include <vector>
#include <string>
using namespace std;
//DFS的直观使用（深度优先搜索）
//也可以用广度优先搜索完成这道题目

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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> Solutions;
        backtrack(Solutions, root, "");
        return Solutions;
    }

    void backtrack(vector<string> &solutions, TreeNode *root, string path)
    {
        if (root != NULL)
        {
            path += to_string(root->val);
            if (root->left == NULL && root->right == NULL)
            {
                solutions.push_back(path);
            }
            else
            {
                path = path + "->";
                backtrack(solutions, root->left, path);
                backtrack(solutions, root->right, path);
            }
        }
    }
};