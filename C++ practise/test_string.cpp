#include <iostream>
int main(){
    using namespace std;
    char shirt_size[] ="S"; //char shirt_size = "s" is illegal!
    
    cout << shirt_size;

/////////////////////////////////////////////////////////////

    const int Arsize = 20;
    char name[Arsize];
    char dessert[Arsize];

    cout << "Enter your name:\n";
    cin.getline(name,Arsize);
    cout << "Hi, " << name;
    cout << " What is your favorite dessert?" <<endl;
    cin.getline(dessert,Arsize); 
    cout <<"I have some delicious "<< dessert << " for you, "<<name;
    //getline() 不保存换行符，而是将其替换成\0保存在字符串中作为字符串的结尾。
    //get() 将换行符留在输出队列中。
    //同时这里涉及cin.get的多个版本（函数重载）


    cin.get();
    return 0;
}