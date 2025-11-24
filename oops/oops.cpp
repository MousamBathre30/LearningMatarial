#include<bits/stdc++.h>
using namespace std; 

class Human{
    public:
       string name;
       string occupation;
       int age;

       void eat(){
        cout<<"This person is eating "<<endl;
       }

       void drink(){
          cout<<"This person is drinking "<<endl;
       }
       void sleep(){
         cout<<"This person is sleeping  "<<endl;
       } 

}; 

int main(){
    Human human1;
    Human human2;
    human1.name="Rick";
    human1.occupation="scientist";
    human1.age=59;

     human2.name="mousam";
    human2.occupation="programmer";
    human2.age=20;
     
    
    cout<<human2.name<<endl;
    cout<<human2.occupation<<endl;
    cout<<human2.age<<endl;
   

    human2.eat();
    human2.drink();
    human2.sleep();
  return 0;
}