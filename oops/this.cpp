class Student{
    public:
     string name;
     int age;
     double gpa;
      Student(string name , int age, double gpa){
               this->name=name;
               this->age=age;
               this->gpa=gpa;
      }
};

// this is a special type of pointer that points to the current object 
// tis -> prop is same as *(this) prop