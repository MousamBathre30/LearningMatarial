
#include <bits/stdc++.h>
using namespace std;

/*
    static variables variable declare as 
    static in a function are created and initialised once for the lifetime
    of the program


    static variable in a class are created and initialised once.
    they are shared by all the objects of the class 
*/

 void fun(){
static int x=0;
    cout << x <<endl;
    x++;
 }

    int main(){
   fun();
    fun();
    return 0;
}