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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> solu;
        TreeNode *temp = NULL;
        while (root != NULL)
        {
            if (root->left == NULL)
            {
                solu.push_back(root->val);
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
                    solu.push_back(root->val);
                    temp->right = NULL;
                    root = root->right;
                }
            }
        }
        return solu;
    }
};