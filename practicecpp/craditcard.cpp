#include <iostream>
using namespace std;


int getDigit(const int number);
int sumOddDigits(const string cardNumber);
int sumEvendigits(const string cardNumber);
int main(){
     string cardNumber;
     int result=0;
     cout<<"Enter the credit card #";
     cin>>cardNumber;
     result=sumEvendigits(cardNumber)+sumOddDigits(cardNumber);
     if(result % 10 == 0){
        cout<<"CARd number is valid "<<endl;
     }else {
        cout<<"nope meri jaan"<<endl;
     }

    return 0;

}

int getDigit(const int number){
return number%10+(number/10%10);// 
}
int sumOddDigits(const string cardNumber){ 
    int odd = 0;
    for(int i=cardNumber.size()-1; i>=1; i-=2){
        odd+=getDigit((cardNumber[i]-'0')*2);
    }
    return odd;
 return 0;
}
int sumEvendigits(const string cardNumber){
    int sum = 0;
    for(int i=cardNumber.size()-2; i>=0; i--){
        sum+=getDigit((cardNumber[i]-'0')*2);
    }
    return sum;
}