#include <iostream>

using namespace std;
class Point{
    private: 
        int x,y;
    public:
        Point(int _x=0, int _y=0){x=_x; y=_y;}
        Point(Point &p){
            x = p.x;
            y = p.y;
        }
        void ShowPosition(){cout<<x<<", "<<y<<endl;}
        void operator+(int val){
            x = x + val;
            y = y + val;
        }
        /*
        void operator=(const Point &p){
            x = p.x;
            y = p.y;
        }
        */
        Point& operator=(const Point &p){
            x = p.x;
            y = p.y;
            return *this;
        }
};

int main(){
    Point p1(1,2);
    Point p2(2,4);
    Point p3 = p1;
    
    p3 = p2 = p1;
    p3.ShowPosition();
    p2.ShowPosition();

}

