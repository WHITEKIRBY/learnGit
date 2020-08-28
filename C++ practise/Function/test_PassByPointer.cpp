#include <iostream>
void swap(int* x,int* y){
    int t = 0;
    t = *x; 
    *x = *y; 
    *y = t;
}

int main()
{
    using namespace std;
    int x{5},y{10};
    cout <<"Before"<<endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;    
    
    swap(&x,&y);
    
    cout << "After" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    cin.get();
    return 0;
}