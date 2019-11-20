#include <iostream>
using namespace std;
namespace A{
// code from Alice
    void sayHello(){
        cout<<"Hello from Alice"<<endl;
    }
}
namespace B{
// code from Bob 
    void sayHello(){
        cout<<"Hello from Bob"<<endl;
    }
}
using namespace A;
using namespace B;
int main()
{
    A::sayHello();
    B::sayHello();

    sayHello();
}
