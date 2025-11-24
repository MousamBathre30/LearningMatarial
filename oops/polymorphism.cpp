#include <bits/stdc++.h>
using namespace std;
class solve{
    public:

    void add(int x){
        cout << "the value of x is " << x <<endl;
    }

    void add(double x){
        cout << "the value of x is " << x << endl;
    }
};
// compile time polymorphism 

class baseclass{
    public:
    virtual void display(){
        cout << "this display of base class" <<endl;
    }
};

class derivedclass : public baseclass{
    public:
    void display(){
        cout<<"this is derived class" <<endl;
    }
};


class parent{
  public:
   void getInfo(){
    cout<< "thapd maroungi"<<endl;
   }
};
class Child : public parent{
    public:
    void getInfo(){
        cout<<"bacha thapad marenga"<<endl;
    }
};
int main(){
    // solve s;
     derivedclass obj;
     baseclass &bs = obj;
     bs.display();

    // s.add(3.6);
    // s.add(4);
   
    //obj.display();
    parent p;
    p.getInfo();
    Child c;
    c.getInfo();
    return 0;
}

// runtime polymorphism  use inheritance 


// virtual funcations 
/*
     virtual functions are dynamic in nature.
     definded nu the kwyword 'virtual' inside a base class and are always declard
     with a base class and overridden in a child class.
     a virtual function is called during runtime.
*/