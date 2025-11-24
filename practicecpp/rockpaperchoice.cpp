#include <bits/stdc++.h>
#include <ctime>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWimmer(char plyer, char computer);
int main(){
    char player;
    char computer;
    cout<<"How many time do you want to play this game " <<endl;
    int time;
    cin>>time;
    while(time--){
    player=getUserChoice();
    cout<<"Your choice : ";
    showChoice(player); 

    computer=getComputerChoice();
    cout<<"Computer's choices  : ";
    showChoice(computer);
    chooseWimmer(player,computer);
    }
    return 0;
}

char getUserChoice(){ 
    char player;
    cout<<"Rock-Paper-Scissors Game"<<endl;
    
    do{
      cout<<"choose one of the funcation "<<endl;  
    cout<<"*************************"<<endl;
    cout<<"'r' for rocks"<<endl;
    cout<<"*************************"<<endl;
    cout<<"'p' for paper"<<endl;
    cout<<"*************************"<<endl;
    cout<<"'s' for scissors"<<endl;
    cout<<"*************************"<<endl;
    cout<<"input your choice mere jaan " <<endl;
    cin>>player;
    }while(player != 'r' && player != 'p' && player !='s');
  
    
    return player;
}
char getComputerChoice(){ 
    srand(time(0));
    int num=rand()%3+1;
    switch (num)
    {
    case 1: return 'r';
    case 2: return 'p';       
    case 3: return 's';
    
    
    default:
        break;
    }
    return 0;
}
void showChoice(char choice){
    switch (choice)
    {
    case 'r': cout<<"Rock"<<endl;
        break;
    case 'p': cout<<"Paper "<<endl;
        break;    
    case 's': cout<<"Sessiors "<<endl;
        break;
    default: 
        break;
    }
}
void chooseWimmer(char player, char computer){
    switch (player)
    {
    case 'r': if(computer =='r'){
                 cout<<"It is a tie bro "<<endl;
               }else if(computer == 'p'){
                cout<<"^^^^^^^^^^^^^You loose the match ^^^^^^^^^^^^^^ "<<endl;
               }else{
                cout<<"You win the match baby : ";
               }
               break;
    case 'p': if(computer =='p'){
                 cout<<"It is a tie bro "<<endl;
               }else if(computer == 's'){
                cout<<"You loose the match "<<endl;
               }else{
                cout<<"You win the match baby : ";
               }
               break;

    case 's': if(computer =='s'){
                 cout<<"It is a tie bro "<<endl;
               }else if(computer == 'p'){
                cout<<"You loose the match "<<endl;
               }else{
                cout<<"You win the match baby : ";
               }
               break;                      
    default:
        break;
    }
     
}