#include <iostream>

class super{
    int a;
    public:
    super(int _a){a=_a;}
};
class mid: public super{
    int a;
    public:
    mid(int _a): super(_a)
    {a=_a;}
};
class sub: public mid{
    int a;
    public:
    sub(int _a): mid(_a)
    {a=_a;}
};


int main()
{
    sub s(10);
}
