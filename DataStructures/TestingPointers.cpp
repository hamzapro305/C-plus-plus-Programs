#include<iostream>
using namespace std;

struct Person{
    int id;
    int age;
};

void printOBJ(Person *obj){
    cout << obj->id << " " << obj->age << endl;
}

int main(){
    Person *obj1 = new Person[2];
    obj1->id = 1;
    obj1->age = 20;
    (obj1 + sizeof(Person))->id = 2;
    (obj1 + sizeof(Person))->age = 22;
    printOBJ(obj1);
    printOBJ(obj1 + sizeof(Person));
    free(obj1);
    return 0;
}