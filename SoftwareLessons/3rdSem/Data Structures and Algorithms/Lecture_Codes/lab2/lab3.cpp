#include <cstdlib>
#include <iostream>

using namespace std;
class employee
{
	//write the employee class content
	//...
private:
	string name;

private:
	string surname;

private:
	string id;

private:
	string pos;

public : 
	void setName(string s)
	{
		name = s;
	}
	string getName()
	{
		return name;
	}

public:
	void setSurname(string b)
	{
		surname = b;
	}
	string getSurname()
	{
		return surname;
	}

public:
	void setId(string d)
	{
		d = id;
	}
	string getId()
	{
		return id;
	}

public:
	void setPos(string k)
	{
		k = pos;
	}
	string getPos()
	{
		return pos;
	}



};



int main()
{
	string name;
	string surname;
	string id;
	string pos;

	employee* emp = new employee();
	//Enter employee information:
	cout << "Enter employee information:" << endl;
	cout << "\tname="; cin >> name;
	emp->setName(name);

	cout << "\tsurname="; cin >> surname;
	emp->setSurname(surname);

	cout << "\tid="; cin >> id;
	emp->setId(id);

	cout << "\tpos="; cin >> pos;
	emp->setPos(pos);






	// continue writing the code:
	//...
	return 0;
}