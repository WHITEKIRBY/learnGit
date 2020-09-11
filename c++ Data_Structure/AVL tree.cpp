#include <iostream>
using std::max;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(AvlTree T, int X);
Position FindMax(AvlTree T);
Position FindMin(AvlTree T);
AvlTree Insert(AvlTree T, int X);
AvlTree Delete(AvlTree T, int X);
int Retrieve(Position P);
static int Height(Position P);
static Position SingleRotationWithLeft(Position T);
static Position SingleRotationWithRight(Position T);
static Position DoubleRotationWithLeft(Position T);
static Position DoubleRotationWithRight(Position T);

struct AvlNode
{
    int Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

int main()
{
    return 0;
}

static int Height(Position P)
{
    if (P == NULL)
    {
        return -1;
    }
    else
    {
        return P->Height;
    }
}

static Position SingleRotationWithLeft(Position k2)
{
    Position k1;
    k1 = k2->Left;
    k2->Left = k1->Right;
    k1->Right = k2;

    k2->Height = max(Height(k2->Left), Height(k2->Right)) + 1;
    k1->Height = max(Height(k1->Left), Height(k1->Right)) + 1;

    return k1;
}

static Position SingleRotationWithRight(Position k1)
{
    Position k2;
    k2 = k1->Right;
    k1->Right = k2->Left;
    k2->Left = k1;

    k1->Height = max(Height(k1->Left), Height(k1->Right)) + 1;
    k2->Height = max(Height(k2->Left), Height(k2->Right)) + 1;

    return k2;
}

static Position DoubleRotationWithLeft(Position k3)
{
    //Rotate between k1 and k2;
    k3->Left = SingleRotationWithRight(k3->Left);
    //Rotate between k3 and k2;
    return SingleRotationWithLeft(k3);

    //     Position k1, k2;
    //     k1 = k3->Left;
    //     k2 = k1->Right;
    //     k1->Right = k2->Left;
    //     k3->Left = k2->Right;
    //     k2->Left = k1;
    //     k2->Right = k3;

    //     k1->Height = max(Height(k1->Left), Height(k1->Right)) + 1;
    //     k3->Height = max(Height(k3->Left), Height(k3->Right)) + 1;
    //     k2->Height = max(Height(k2->Left), Height(k2->Right)) + 1;

    //     return k2;
}

static Position DoubleRotationWithRight(Position k1)
{
    k1->Right = SingleRotationWithLeft(k1->Right);
    return SingleRotationWithRight(k1);
    // Position k2, k3;
    // k3 = k1->Right;
    // k2 = k3->Left;
    // k1->Right = k2->Left;
    // k3->Left = k2->Right;
    // k2->Left = k1;
    // k2->Right = k3;

    // k1->Height = max(Height(k1->Left), Height(k1->Right)) + 1;
    // k3->Height = max(Height(k3->Left), Height(k3->Right)) + 1;
    // k2->Height = max(Height(k2->Left), Height(k2->Right)) + 1;

    // return k2;
}

AvlTree Insert(AvlTree T, int X)
{
    if (T == NULL)
    {
        T = new AvlNode;
        if (T == NULL)
        {
            std::cout << "Out of Space!";
            return T;
        }
        else
        {
            T->Height = 0;
            T->Left = T->Right = NULL;
            T->Element = X;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(T->Left, X);
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (X < T->Left->Element)
            {
                T = SingleRotationWithLeft(T);
            }
            else
            {
                T = DoubleRotationWithLeft(T);
            }
        }
    }
    else if (X > T->Element)
    {
        T->Right = Insert(T->Right, X);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (X > T->Right->Element)
            {
                T = SingleRotationWithRight(T);
            }
            else
            {
                T = DoubleRotationWithRight(T);
            }
        }
    }
    T->Height = max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}
