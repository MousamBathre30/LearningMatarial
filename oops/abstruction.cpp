#include <bits/stdc++.h>
using namespace std;

/*
    abstruction using abstrcat classes
    abstruct classes are used to provode a base class from which other classes can be derived.
    they cannot be instantiated ad are meant to be inherited.
    abstract classes are typically ised to define an interface for derived classes.
*/
class Shape {
      virtual void drav()=0; // pure virtual function
    };
class circle : public Shape{
    public:
    void draw(){
        cout << "jai "<<endl;
    }
}
    int main(){
     circle c;
     c.draw();
    return 0;
}