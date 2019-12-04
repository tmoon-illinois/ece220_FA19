#include <iostream>
using namespace std;
/*
int Add(int a, int b){
    return a+b;
}
double Add(double a, double b){
    return a+b;
}
*/

template <class T>
T Add(T a, T b){
    return a+b;
}
template <class T1, class T2>
void Print(T1 a, T2 b){
    cout<<a<<endl;
    cout<<b<<endl;
}


int main(){
    cout<<Add(1, 3)<<endl;
    cout<<Add(1.2, 2.5)<<endl;

    Print(2,'b');
}
