#include <iostream>

void Msort(int a[], int tmp[], int left, int right)
{
    int center;

    if (left < right)
    {
        center = (left + right) / 2;
        Msort(a, tmp, left, center);
        Msort(a, tmp, center + 1, right);
        Merge(a, tmp, left, center + 1, right);
    }
}

void Merge(int a[], int tmp[], int Lpos, int Rpos, int rightend)
{
    int i, Leftend, tmppos, Num_element;

    Leftend = Rpos - 1;
    tmppos = Lpos;
    Num_element = rightend - Lpos + 1;

    while (Lpos <= Leftend && Rpos <= rightend)
    {
        if (a[Lpos] > a[Rpos])
            tmp[tmppos++] = a[Rpos++];
        else
            tmp[tmppos++] = a[Lpos++];
    }

    while (Lpos <= Leftend)
    {
        tmp[tmppos++] = a[Lpos++];
    }
    while (Rpos <= rightend)
    {
        tmp[tmppos++] = a[Rpos++];
    }

    for (i = 0; i < Num_element; i++, rightend--)//多个循环条件变化用逗号分隔！
    {
        a[rightend] = tmp[rightend];
    }
}

void MergeSort(int a[], int n)
{
    int *tmp = new int[n];
    //作为一名谨慎的程序员，应随时注意分配内存时是否分配成功！
    if (tmp != NULL)
    {
        Msort(a, tmp, 0, n - 1);
        delete[] tmp;
    }
    else
    {
        std::cout << "can't allocated new space for tmparray!";
        std::abort();
    }
}