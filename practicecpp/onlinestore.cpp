// STL standard template library 

// partation containers -> Algorithms -> iterators 

// online store ->
// vector -> store a list of products 
// list -> order for product 
// deque -> visit of customer 
// set -> always for unique value catagory 
// map -> stock count
// multimap -> allowing mutipal order 
// unordered_map -> 
// unordered_Set -> 


#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>


using namespace std;

struct Product
{
    /* data */
    int productID;
    string name;
    string category;
};

struct Order
{
    /* data */
    int orderID;
    int ProductID;
    int quesntity;
    string customerID;
    time_t orderDates;
};

int main(){
    vector<Product> products = {
        {101,"laptop","electornic"},
         {102,"phone","electornic"},
          {103,"cofffe mug","kitchen"},
           {104,"blender","kitchen"},
            {101,"desk lamp ","Home"},
    };
    deque<string> recentCustomers = {"C001" , "C002", "C003"};

    recentCustomers.push_back("C004");
    recentCustomers.push_front("C005");


    list<Order> orderHistory;
    orderHistory.push_back({1,101,1,"C001",time(0)});
    orderHistory.push_back({2,102,2,"C002",time(0)});
    orderHistory.push_back({3,103,1,"C003",time(0)});

    set<string> categories;
    
    for(const auto &product : products){
        categories.insert(product.category);
    }

    map<int,int> productStock = {
          {101,10},
          {102,90},
          {103,80},
          {104,10},
          {105,30},
    };

    multimap<string,Order> customerOrders;
    for(const auto &order : orderHistory){
        customerOrders.insert({order.customerID,order});
    }
    
    unordered_map<string, string> customerData={
        {"C001","Alice"},
        {"C002","clice"},
        {"C003","dlice"},
        {"C004","jlice"},
        {"C005","mlice"},
    };

    unordered_set<int> uniqueProductIDs;

    for(const auto &product:products){
        uniqueProductIDs.insert(product.productID);
    }

    for(const auto &product : products){
        cout<< product.productID <<endl;
         cout<< product.category <<endl;
          cout<< product.name <<endl;
    }

    return 0;
}
