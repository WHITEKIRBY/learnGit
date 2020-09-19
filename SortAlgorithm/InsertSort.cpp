#include <iostream>
//

void InsertSort(int a[], int n)
{
    int j, i;
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i; j > 0 && a[j-1] > temp;j--){
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}

int main()
{
    int a[10] {1,2,3,5,4,7,6,5,8,7};
    InsertSort(a,10);

    std::cin.get();
    return 0;
}