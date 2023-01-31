
#include <iostream> 
#include "operations.hpp"
using namespace std;

//using namespace ns1;
using namespace ns2;

int main() 
{ 
    // Access value function within ns2 
    cout<<"ns2::value(2) = "<<ns2::value(2)<<endl;  
  
    // Access value function within ns1 
    cout<<"ns1::value(2) = "<<ns1::value(2)<<endl;
  
    // Access variable x directly 
    cout <<"ns1::C        = "<< ns1::C <<endl;
    cout <<"ns2::C        = "<< ns1::C <<endl;
    
    return 0; 
} 
