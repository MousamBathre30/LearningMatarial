#include <bits/stdc++.h>
using namespace std;

// encapsulation is wrapping up of data and member functions in a single unit called class.
  // <<<<<< dataProperty >>>>>>
  // data hiding private
class account {
      private:
      int balance=0;
      int passley;
      public:
      int id;
      int accountnumber=0;
    };

    int main(){
     account obj;
     cout<< obj.accountnumber << endl;
    return 0;
}