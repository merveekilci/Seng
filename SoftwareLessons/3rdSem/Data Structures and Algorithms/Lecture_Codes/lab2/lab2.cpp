#include <cstdlib> 
#include <iostream> 
using namespace std;
class employee
{
//write the employee class content
//... 
private:
    string Name;
private:
    string Surname;
private:
    string Id;
private:
    string position;

public:
    void setName(string name)
    {
        Name=name;
    }  


    string getName()
    {
        return Name;
    }

    void setID(string id)
    {
        Id=id;
    } 



    int getID()
    {
        return Id;

    }

    void setPositon(string position)
    {
        
    }






};
int main() 
{
        string name;
        string surname;
        string id;
        string pos;
employee *emp=new employee();
//Enter employee information:
cout<<"Enter employee information:"<<endl; 
cout<<"\tname=";cin>>name; 
emp->setName(name);
// continue writing the code:
//...


return 0; }
