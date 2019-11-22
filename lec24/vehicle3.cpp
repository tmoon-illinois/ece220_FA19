#include <iostream>
using namespace std;
class Vehicle{
    protected:
    int passenger;
    double baggage;
    public:
    Vehicle(){}
    Vehicle(int person, double weight){
        passenger = person;
        baggage = weight;
    }
    void Ride(int person){  passenger += person;}
    void Load(double weight){   baggage += weight;}
    int getPassenger(){ return passenger;}
    double getBaggage(){ return baggage;}
};
class Airplane : public Vehicle{
    int crew_man;
    public:
    Airplane(int person, double weight, int crew){ 
        passenger = person;
        baggage = weight;
        crew_man = crew;
    }
    void TakeCrew(int crew){    crew_man += crew;}
    int getCrew(){  return crew_man;}
    void ShowData(){
        cout<<"<<Airplane>> "<<endl;
        cout<<"passenger: "<<getPassenger()<<endl;
        cout<<"baggage: "<<getBaggage()<<endl;
        cout<<"crew man: "<<getCrew()<<endl;
    }
};

class Train : public Vehicle{
    int length;
    public:
    Train(int person, double weight, int len) {    
        passenger = person;
        baggage = weight;
        length = len;
    }
    void AddLength(int len){length += len;}
    int getLength(){return length;}
    void ShowData(){
        cout<<"<<Train>> "<<endl;
        cout<<"passenger: "<<getPassenger()<<endl;
        cout<<"baggage: "<<getBaggage()<<endl;
        cout<<"length : "<<getLength()<<endl;
    }
};


int main(){
    Airplane a(120, 1300.0, 10);
    a.ShowData();
}



