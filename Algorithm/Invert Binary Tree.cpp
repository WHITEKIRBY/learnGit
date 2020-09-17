#include <iostream>

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return root;
        }
        else if (root->right == NULL)
        {
            root->right = root->left;
            root->left = NULL;
            root->right = invertTree(root->right);
        }
        else if (root->left == NULL)
        {
            root->left = root->right;
            root->right = NULL;
            root->left = invertTree(root->left);
        }
        else
        {
            TreeNode *temp;
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
        }
        return root;
    }
};