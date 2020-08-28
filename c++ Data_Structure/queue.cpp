#include <iostream>
#define Maxsize 50
//One of reasonable solutions to the disadvantage of sequential storage,
//is using round-robin queue.
typedef struct{
    int data[Maxsize];
    int frout,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.frout = Q.rear = 0;
}

bool QueueEmpty(SqQueue &Q){
    if (Q.rear == Q.frout)
        return true;
    else
        return false;
}

int main(){
    using namespace std;
    int y[5] = {1,2,3,4,5};
    cout << y[0];
    y[0] = 3;

    cout << y[0];
    cout << y[5];

    cin.get();
    return 0;
}