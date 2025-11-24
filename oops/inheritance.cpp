#include <bits/stdc++.h>
using namespace std;

class vehical{
    public:

    void run(){
        cout << "The speed of car " <<endl;
    }
};

class car : public vehical{
    public:
    void feature(){
        cout<<"the feature of car is "<<endl;
    }
};

/// singal inheritance 

class tata :  public car{
    public:
    void tata_feature(){
        cout<< "the feature of tata is "<<endl;
    }
};

// multilevel inheritance 

class mahindra{
    public:
    void mahindra_feature(){
        cout << "the feature of hahindra "<<endl;
    }
};

class tesla{
    public:
    void tesla_feature(){
        cout << "the feature of tesla "<<endl;
    }
};

class automatic : public mahindra , public tesla{
    public:
    void autofeature(){
        cout<< "The feature of autombile " << endl;
    }
};

// multipal inheritance 


class mahindra_suv : public mahindra{
    public:
    
    void suv(){
        cout << "mahindra suv"<<endl;
    }
};

class mahindra_roadtrap : public mahindra{
    public:

    void roadtrap(){
        cout << "Your road trip is best "<<endl;
    }
};
// hearical inheritance 

int main(){
    mahindra_roadtrap obj;
    obj.mahindra_feature();
    mahindra_suv obj2;
    obj2.mahindra_feature();
    return 0;
}