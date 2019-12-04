#include <iostream>

using namespace std;

class AAA{
    private:
        int x;
    public:
        AAA(){ x=0;}
        void Print(){ cout<<x<<endl;}
        friend void setX(AAA &a, int x);
        friend class BBB;
        void setY(BBB &b, int y){
            b.y = y;
        }
};
class BBB{
    private:
        int y;
    public:
        void setX(AAA &a, int x){
            a.x = x;
        }
};

void setX(AAA &a, int x){
    a.x= x;
}

int main(){
    AAA a;
    a.Print();

    setX(a, 10);
    a.Print();

    BBB b;
    b.setX(a, 20);
    a.Print();
}
