#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>


using namespace std;


struct employeeManegement
{
    /* data */
    int id;
    string name;
    double salary;
};

// & second reference & last refecnce
void displayEmployee(const employeeManegement& emp){
     cout << "ID" << emp.id << "Name of the employe " <<  emp.name << "Salary: $ " << emp.salary <<endl;
}

int main(){
    
    vector<employeeManegement> employees = {
        {101 , "hitesh" , 1000},
        {102 , "ritesh" , 2000},
        {103 , "mitesh" , 3000},
        {104 , "jitesh" , 4000},
        {105 , "nitesh" , 5000},
    };

    // sort 
    sort(employees.begin(),employees.end(),[](const employeeManegement& e1, const employeeManegement& e2){
         return e1.salary > e2.salary;
    });
   
    cout<< "employees sorted by salary -> highest to lowest //n"<<endl; 

    for_each(employees.begin(), employees.end(), displayEmployee);

    vector<employeeManegement> highEarners;

    copy_if(employees.begin(), employees.end(), back_inserter(highEarners), [](const employeeManegement& e){
         return e.salary > 3000;
    });

  cout<< "employees who are high earners "<<endl; 

    for_each(highEarners.begin(), highEarners.end(), displayEmployee);
    
    double total = accumulate(employees.begin(), employees.end(), 0.0,[](double sum, const employeeManegement& e){
         return sum+e.salary;
    });
  

    double avg_sal = total / employees.size();

   auto highestPaid = max_element(employees.begin(), employees.end(), [](const employeeManegement& e1, const employeeManegement& e2){
            return e1.salary < e2.salary;
    });

    return 0;
}