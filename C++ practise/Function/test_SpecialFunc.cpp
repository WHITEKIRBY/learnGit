#include <iostream>

using namespace std;
auto max(int x,int y){
    return x > y ? x : y;
}
auto max(int a,int b,int c){
    return max(a,max(b,c));
}
int i{100};
int main(){
    //Variable Scope
    //int i{100}
    for (int i = 0; i < 5;i++){
        cout << i << " ";
        //C++11 std::to_string
        cout << std::to_string(i) + "#";
        cout << ::i << endl;
    }
    //Overloading Function
    cout << max(1,2,3);
    //Default Argument

    cin.get();
    return 0;
}