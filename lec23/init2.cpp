#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char *name;
    int age;
    public:
    Person(){};
    Person(char const *_name, int _age);
    void ShowData();
    ~Person();
};
Person::Person(char const *_name, int _age){
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    age = _age;
}
Person::~Person(){
    cout<<"Destruct "<<name<<endl;
    delete []name;
}
void Person::ShowData(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
}

int main(){
    /*
    Person p1 = Person("Alice", 20);
    Person p2 = Person("Bob", 22);
*/
    Person p[2] = {Person("Alice", 20), Person("Bob", 22) };
    p[0].ShowData();
    p[1].ShowData();

    Person *ptr[2];
    ptr[0] = new Person("Alice",20);
    ptr[1] = new Person("Bob",22);
    ptr[0]->ShowData();
    ptr[1]->ShowData();
   
    //Person &ref = *ptr[0];
    //ref.ShowData();
   
    Person &ref = p[0];
    ref.ShowData();
    
    delete ptr[0];
    delete ptr[1];


}
