#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char *name;
    int age;
    public:
    Person(){};
    Person(const char *_name, int _age);
    //Person(const Person &p);
    void ShowData();
    ~Person();
};
Person::Person(const char *_name, int _age){
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    age = _age;
}
/*
Person::Person(const Person &p){
    name = p.name;
    age = p.age;
}*/
Person::~Person(){
    delete []name;
}
void Person::ShowData(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
}

int main(){
    Person p1 = Person("Alice", 20);
    Person p2(p1);
    p1.ShowData();
    p2.ShowData();
}
