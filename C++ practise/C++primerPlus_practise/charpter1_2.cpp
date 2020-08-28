#include <iostream>
void show_Taxt(int,int);

int main(){
    using namespace std;
    int hours;
    int minutes;
    cout << "Enter the number of hours:";
    cin >> hours;
    cout << "Enter the number of minutes:";
    cin >> minutes;
    show_Taxt(hours,minutes);
    return 0 ;
}


void show_Taxt(int hours,int minutes){
    using namespace std;
    cout << "Time: " << hours << ":" << minutes;
    cin.get();
    cin.get();//why? why need 2 cin.get() to avoid the shut down of the terminal?
}