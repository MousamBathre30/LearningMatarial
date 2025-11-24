#include<bits/stdc++.h>
using namespace std; 


// parameterized constrctor
class Student{
    public:
     string name;
     int age;
     double gpa;
      Student(string name , int age, double gpa){
               this->name=name;
               this->age=age;
               this->gpa=gpa;
      }
      void getInfo(){
        cout<< "jai mata di" <<endl;
      }
};

class ex1{
       public:
       ex1(){
        cout<< "constructor of ex1" <<endl;
       }
};


// copy costructor 
// special constructor default used to copy properties of one object into
// another.

// shallow and deep copy

// a shallow copy of an object copies all of the member values from ine 
// object to another 

// deep copy on the other hand not only copies the member values but also makes
// copies of any dynamocally allocated memor that the members point to.
// stack and heap memory 


int main(){
    // constructor=special method that is automatically called when an object
    // is instantiated useful for assigning values to attributes as arguments
     Student student1("mousam ", 22 , 3.33); 
    cout<< student1.name<<endl;
    cout<<student1.age<<endl;
    cout<<student1.gpa<<endl;
    Student t2(student1);
    t2.getInfo();
    ex1 obj;

    return 0;
}