#include <iostream>

int f(int a, int b = 1, int c = 2){
    return a*b*c;
}
using namespace std;
int main()
{
    int a=10, b=1;
    char c = 'A';

    cout << a <<"," << b << ","<< c << endl;

    cout << (c = 3) <<endl;
    cout << f(a,c=3) <<std::endl;
}
