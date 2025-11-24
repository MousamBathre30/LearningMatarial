#include<bits/stdc++.h>
using namespace std;

int main(){ 
    string question []={
                         "1. what was the year of creation of CPP ?: ",
                         "2. Who invented CPP ?: ",
                         "3. What is the predecessor of CPP ",
                         "4. who is the best language for compatative programming"
                         };

    string options[][4]={{ "A. 1969", "B. 1975","C. 1985","D. 1989" },
                        { "A. Guido Van Rossum", "B. Bjarne Stroustrup","C. Jonh ","D. Mark Mount"},
                        {"A. C", "B. C+","C. C++","D. B++"},
                        {"A. CPP", "B. Python","C. Java","D. GO"}};  


    char anskerkey[]={'C','B','A','A'}; 

    int size=sizeof(question)/sizeof(question[0]); 
    char guess;
    int score=0;
    
    for(int i=0; i<size; i++){
        cout<<"*********************"<<endl;
        cout<<question[i]<<endl;
        cout<<"*********************"<<endl;

        for(int j=0; j<sizeof(options[i])/sizeof(options[i][0]); j++){
            cout<<options[i][j]<<endl;
        }
        cin>>guess;
        guess=toupper(guess);
        
        if(guess == anskerkey[i]){
            cout<<"Correct"<<endl;
            score++;
        }else{
              cout<<"Wrong"<<endl;
              cout<<"Answer"<<anskerkey[i]<<endl;
        }
    }
    cout<<"*********************"<<endl;
    cout << "Result "<<endl; 
    cout<<"*********************"<<endl;
    cout<<"total qustion "<<size<<endl;
    cout<<"Correct guess "<<score<<endl;
    cout<<"Wrong guess "<<size-score<<endl;
    cout<<"Score "<<(score/(double)size)*100 <<"%" <<endl;
    
    return 0;
}