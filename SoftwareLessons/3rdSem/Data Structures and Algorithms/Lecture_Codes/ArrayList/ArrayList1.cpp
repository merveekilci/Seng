//============================================================================
// Name        : ArrayList1.cpp
//============================================================================
#include <iostream>
using namespace std;
#define MAX_SIZE 10

class ArrayList //vector
{
private:
	int *Elements;
	int n;
	int capacity;

	void resize()
	{// increase the array size two times
		int newcap=2*capacity;
		int *Temp=new int[newcap];
		for (int i=0;i<n;i++)
			Temp[i]=Elements[i];
		delete[] Elements;//delete old array
		Elements=Temp;//use new array
		capacity=newcap;
		cout<<"new capacity="<<capacity<<endl;
	}
public:
	ArrayList(int capacity = MAX_SIZE ) //constructor
	{
		this->capacity = capacity;
		Elements = new int[capacity]; //heap
		n = 0;
		cout << "constructor capacity=" << capacity << endl;
	}

	void add(int veri) //push_back
	{
		if (n == capacity) { //is capacity full
			//cout << "capacity full" << endl;
			resize();
		}
		Elements[n] = veri;
		n++;
	}
	int get(int pos) //throw (exception)
	{
		if (pos < 0 || pos >= n) {
			throw exception();
		}
		return Elements[pos];
	}
	~ArrayList() //destructor
	{
		delete[] Elements;
		cout << "destructor worked" << endl;
	}
	void print() {
		cout << "--Elements:" << endl;
		for (int i = 0; i < n; i++)
			cout << "\t" << Elements[i] << endl;
	}
	void remove(int pos) //throw (exception) before c++11
	{
		if (pos < 0 || pos >= n) {
			throw exception();
		}
		n--;
		for (int i = pos; i < n; i++)
			Elements[i] = Elements[i + 1];
	}

	void clear() {
		delete[] Elements;
		n = 0;
	}

	int length() {
		return n;
	}
};

int main() {
	ArrayList *list1 = new ArrayList(3);
	list1->add(10);  //0
	list1->add(8);   //1
	list1->add(100); //2
	list1->add(11);  //3
	list1->add(55);  //4
	list1->add(88);  //5
	list1->add(21);

	try {
		cout << "list1->get(5)=" << list1->get(5) << endl;
		cout << "list1->get(50)=" << list1->get(50) << endl;
	} catch (exception &e) {
		cout << e.what() << endl;
	}

	list1->print();
	cout << "list1->length()=" << list1->length() << endl;
	list1->remove(1);
	list1->remove(3);

	list1->print();
	cout << "list1->length()=" << list1->length() << endl;

	list1->clear();
	list1->print();
	cout << "list1->length()=" << list1->length() << endl;

	return 0;
}
