#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using std::find;
using std::unordered_set;
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

//速度超过9%，主要是在inorder数组中频繁的find操作造成的
//正确做法应是先遍历一遍inorder数组，建立一个hashmap，之后的find操作都是O（1）的了。
//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/

class Solution
{
public:
    void buildsubtree(TreeNode *root, vector<int>::iterator left, vector<int>::iterator right, vector<int>::iterator pre, vector<int> &preorder, vector<int> &inorder, int i, int &count, unordered_set<int> &se)
    {
        if (i == preorder.size())
        {
            return;
        }
        else
        {
            vector<int>::iterator temp;
            for (int j = i; j < preorder.size(); j++)
            {
                if (count == preorder.size())
                {
                    break;
                }
                if (se.count(preorder[j]) == 1)
                {
                    continue;
                }
                if ((temp = find(left, pre, preorder[j])) != pre)
                {
                    // temp = find(left, pre, preorder[j]);
                    root->left = new TreeNode(preorder[j]);
                    se.insert(preorder[j]);
                    count++;
                    buildsubtree(root->left, left, pre, temp, preorder, inorder, j + 1, count, se);
                }
                else if ((temp = find(pre, right, preorder[j])) != right)
                {
                    // temp = find(pre, right, preorder[j]);
                    root->right = new TreeNode(preorder[j]);
                    se.insert(preorder[j]);
                    count++;
                    buildsubtree(root->right, pre, right, temp, preorder, inorder, j + 1, count, se);
                }
                else
                {
                    return;
                }
            }
        }
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
        {
            return NULL;
        }
        unordered_set<int> se{};
        TreeNode *root = new TreeNode(preorder[0]);
        int count = 1;
        vector<int>::iterator pre = find(inorder.begin(), inorder.end(), preorder[0]);
        buildsubtree(root, inorder.begin(), inorder.end(), pre, preorder, inorder, 1, count, se);
        return root;
    }
};

int main()
{
    vector<int> preorder{3, 1, 2, 4};
    vector<int> inorder{1, 2, 3, 4};
    Solution s;
    TreeNode *head;
    head = s.buildTree(preorder, inorder);
    return 0;
}