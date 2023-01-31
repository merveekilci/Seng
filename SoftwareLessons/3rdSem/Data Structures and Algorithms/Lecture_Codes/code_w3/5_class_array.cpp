#include <iostream>
using namespace std;
class Person{
private:
	string name;
public:
	Person(string name){//constructor
		this->name=name;
	}
	
	friend ostream& operator<<(ostream& out,Person &p){
		out<<p.name<<endl;
		return out;
	}
	~Person(){
		//cout<<"destructor worked"<<endl;
	}
};

void print_person(Person **person, int n){
	for(int i=0;i<n;i++){
		cout<<*person[i];
	}
}
void delete_persons(Person **person, int n){
	for(int i=0;i<n;i++){
		delete person[i];
	}
	delete[] person;
}
int main(){
	Person **persons = new Person*[3];
	persons[0] = new Person("Ahmet");
	persons[1] = new Person("Mehmet");
	persons[2] = new Person("Ayse");

	print_person(persons, 3);
	delete_persons(persons, 3);

	return 0;
}
