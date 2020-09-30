#include <iostream>
#include <algorithm>
#define Cutoff 3
using std::sort;
using std::swap;

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

void Qsort(int a[], int left, int right)
{
    int i, j;
    int pivot;
    if ((left + Cutoff) <= right)
    {
        pivot = Mergethree(a, left, right);
        i = left;
        j = right - 1;
        for (;;)
        {
            //非常巧妙的循环用例，十分的节约空间和时间，相比我的ifelse思路也太拉了
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
        //不要将分割点i也放入快速排序的递归中！
        Qsort(a, left, i - 1);
        Qsort(a, i + 1, right);
    }
    else
    {
        //using InsertSort!
        sort(&a[left], &a[right + 1]);
    }
}

void QuickSort(int a[],int n)
{
    Qsort(a, 0, n - 1);
}

int main()
{
    int a[10]{1, 3, 5, 2, 8, 7, 5, 9, 9, 100};
    QuickSort(a,10);
    // Mergethree(a, 0, 3);
    // sort(&a[0], &a[4]);
    for (auto i : a)
    {
        std::cout << i;
    }
    // std::cout << sizeof(a) / sizeof(a[0]) << std::endl;
    
    std::cin.get();
    return 0;
}