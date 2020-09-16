#include <iostream>
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    int Element;
    SearchTree left;
    SearchTree right;
    TreeNode(int x) : Element{x}, left{NULL}, right{NULL} {};
};

SearchTree MakeEmpty(SearchTree T);
Position Find(int x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
};

Position Find(int x, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (x < T->Element)
        Find(x, T->left);
    else if (x > T->Element)
        Find(x, T->right);
    else
        return T;
}

Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (T->left == NULL)
        return T;
    else
        return FindMin(T->left);
}

Position FindMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (T->right == NULL)
        return T;
    else
        return FindMin(T->right);
}

SearchTree Insert(int x, SearchTree T)
{
    if (T == NULL)
    {
        T = new TreeNode(x);
        if (T == NULL)
            std::cout << "Out of space!";
    }
    else if (x < T->Element)
        T->left = (x, T->left);
    else if (x > T->Element)
        T->right = (x, T->right);
    return T;
}

SearchTree Delete(int x, SearchTree T)
{
    Position Tmpcell;
    if (T == NULL)
        return T;
    else if (x < T->Element)
        T->left = Delete(x, T->left);
    else if (x > T->Element)
        T->right = Delete(x, T->right);
    else if (T->left && T->right)
    {
        Tmpcell = FindMin(T->right);
        T->Element = Tmpcell->Element;
        T->right = Delete(T->Element, T->right);//也可以取左子树最大。
    }
    else
    {
        Tmpcell = T;
        if (T->right == NULL)
            T = T->left;
        else if (T->left == NULL)
            T = T->right;
        delete Tmpcell;
    }
    return T;
}