#include <iostream>
void swap(int x,int y){
    int t = 0;
    t = x; 
    x = y; 
    y = t;
}

int main()
{
    using namespace std;
    int a{5},b{10};
    cout <<"Before"<<endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;    
    
    swap(a,b);
   
    cout << "After" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    cin.get();
    return 0;
}