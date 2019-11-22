#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base() called."<<endl;
        }
        Base(int a){
            cout<<"Base(int a) called."<<endl;
        }
};
class Derived: public Base{
    public:
        Derived(){
            cout<<"Derived() called."<<endl;
        }
        Derived(int a): Base(a){
            cout<<"Derived(int a) called."<<endl;
        }
};

int main(){
    cout<<"<<d1 declared.>>"<<endl;
    Derived d1;
    cout<<"<<d2 declared.>>"<<endl;
    Derived d2(1);
}
