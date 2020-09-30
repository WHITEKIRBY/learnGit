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
    void dfs(TreeNode *root, int &sum)
    {
        if(root != NULL){
            dfs(root->right,sum);
            sum += root->val;
            root->val = sum;
            dfs(root->left,sum);
        }
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};