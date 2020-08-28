//数据结构  第二章 线性表:顺序表
//sqlist
#include <iostream>
#define MaxSize 5

typedef struct 
{
    int data[MaxSize];
    int Length = 0;
}SqList;

bool ListInsert(SqList &L,int i,int e){
    if (i<1||i>L.Length+1)
        return false;
    if (L.Length>MaxSize)
        return false;
    for (int j = L.Length;j>=i;j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.Length++;
    return true;
}
bool ListDelete(SqList &L,int i,int &e){//here, e is to store the deleted element.
    if (i<1||i>L.Length)
        return false;
    for (int j = i;j<L.Length;j++)
        L.data[j-1] = L.data[j];
    L.Length--;
    return true;
}
int GetElem(SqList &L,int i){
    return L.data[i-1];
}
int LocateElem(SqList &L,int e){
    for (int i = 0;i<L.Length;i++){
        if(L.data[i]==e)
            return i+1;
    }
    return 0;
}

bool Delete_Min_ele(SqList &L,int &e){
    if(L.Length == 0)
        return false;
    else
        for (int i = 0; i < L.Length; i++)
        {
            /* code */
        }
        
}

int main()
{
    using namespace std;
    SqList test;
    ListInsert(test,1,2);
    ListInsert(test,2,1);
    ListInsert(test,3,3);
    ListInsert(test,4,5);
    ListInsert(test,5,7);

}
