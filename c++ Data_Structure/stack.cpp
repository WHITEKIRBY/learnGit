#include <iostream>

#define Maxsize 50

typedef struct{
    int data[Maxsize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack &S){
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S,int x){
    if (S.top == Maxsize-1)
        return false;
    S.data[++S.top] = x;
    return true;
    //This statement is equaly to :
    //  S.data[S.top+1] = x;
    //  S.top++;
}

bool Pop(SqStack &S,int &x){
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S,int &x){
    if (S.top == -1)
        return false;
    else
        x = S.data[S.top];
        return true;
}

bool DestroyStack(SqStack &S){
    //对于静态分配的顺序栈，应该直接使S=Null即可。
    return false;
}

int main(){

    return 0;
}