
#include <cstdlib>
#include <iostream>
#include <exception>
using namespace std;

class SmallNumberException:public exception
{
    char *str;
public:
    SmallNumberException(char *str=(char*)"Small Number Exception"){
        this->str=str;
    }
    const char* what() const throw(){
      return str;  
    }
};

class BigNumberException:public exception
{
    char* str;
public:
    BigNumberException(char *str=(char*)"Big Number Exception"){
        this->str=str;
    }
    const char* what() const throw(){
      return str;  
    }
};

void some_op(int a,int b)//throw(BigNumberException,BigNumberException)
{
    if (a<1) throw  SmallNumberException();
    if (a>10) throw BigNumberException();  
    cout<<"some_op= "<<a+b<<endl;    
}

int main(int argc, char** argv) 
{

    try{
        some_op(6,5); // no error
        //some_op(15,5);// BigNumberException
        some_op(0,5);// SmallNumberException
       
    }  
    catch(SmallNumberException &k){        
        cout<<k.what()<<endl;  
        cout<<"trying other alternative:"<<endl;
        some_op(5,5);      
    }
    catch(BigNumberException& k){
        cout<<k.what()<<endl; 
    }
    catch(exception& e){
    	//Exceptions other than above exceptions
        /**We derived both BigNumberException and SmallNumberException
        from exception class. **/
        cout << "exception :";
        cout<<e.what()<<endl;
    }
    
    return 0;
}

