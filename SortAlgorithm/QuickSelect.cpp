#include <iostream>
#include <algorithm>
#define Cutoff 3
using std::sort;
using std::swap;

//将第K个最小元放置在数组第K个位置的算法
//目的是为了解决选择问题，如在快速排序中的枢纽元选取问题。
//因为数组下标从0开始，所以第k个位置就是K-1
//运用快速选择，可以将快速排序的二次运行时间的最坏情形下降到O（N），但额外开销十分巨大，因此可能这只有理论上的意义

int Mergethree(int a[], int left, int right)
{
    int center = (left + right) / 2;
    if (a[left] > a[center])
        swap(a[left], a[center]);
    if (a[center] > a[right])
        swap(a[center], a[right]);
    if (a[left] > a[center])
        swap(a[left], a[center]);
    //a[left] <= a[center] <= a[right]
    swap(a[center], a[right - 1]); //将flag放置于倒数第二位
    return a[right - 1];           //返回选择的flag
}

void QuickSelect(int a[], int k, int left, int right)
{
    int i, j;
    int pivot;
    if (left + Cutoff <= right)
    {
        i = left;
        j = right - 1;
        pivot = Mergethree(a, left, right);
        for (;;)
        {
            while (a[++i] < pivot)
            {
            }
            while (a[--j] > pivot)
            {
            }
            if (i < j)
                swap(a[i], a[j]);
            else
                break;
        }
        swap(a[i], a[right - 1]);
        if (k <= i)
            QuickSelect(a, k, left, i - 1);
        else if (k > i + 1)//k-1 = i 时i处就是第k个最小元。
            QuickSelect(a, k, i + 1, right);
    }
    else
    {
        sort(&a[left], &a[right + 1]);
    }
}