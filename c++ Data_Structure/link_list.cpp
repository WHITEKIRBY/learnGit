#include <iostream>

typedef struct LNode
{
    int data;
    struct LNode* next ;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L){
    int x;
    L = new LNode;
    L->next = nullptr;
    scanf("%d",&x);
    while (x!=9999)
    {
        LNode* s = new LNode;
        s->next = L->next;
        L->next = s;
        s->data = x;
        scanf("%d",&x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L){
    int x;
    L = new LNode;
    LinkList r = L;
    L->next = nullptr;
    scanf("%d",&x);
    while (x!=9999)
    {
        LNode* s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    return L;
}

LNode* GetElem(LinkList L,int i){
    LNode* p = L;
    int j = 1;
    if(i == 0)
        return L;
    while (p&&j<=i)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode* LocateElem(LinkList L,int x){
    LNode* p = L->next;
    while((p != nullptr)&&(p->data!=x))
        p = p->next;
    return p;
}



int main(){
    using namespace std;
    LinkList L;
    List_TailInsert(L);


    cin.get();
    cin.get();
    return 0;
}