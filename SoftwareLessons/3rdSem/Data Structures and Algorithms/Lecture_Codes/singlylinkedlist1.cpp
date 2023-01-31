//============================================================================
// Name        : singlylinkedlist1.cpp
// Description : Simple Singly Linked List implementation using integers
// To do 	   : copy constructor, reverse() method, template implementation
//============================================================================
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int data, Node *next = NULL) {
		this->data = data;
		this->next = next;
	}
};
class SinglyLinkedList {
private:
	Node *head; //pointer to the first element
	int n;

	Node* find(int index) {
		Node *temp = head;
		int count = 0;
		while (temp != NULL) {
			if (count == index)
				break;
			temp = temp->next;
			count++;
		}
		return temp;
	}
public:
	SinglyLinkedList() { //constructor
		head = NULL;
		n = 0;
	}
	void push_front(int data) {
		Node *node = new Node(data);
		if (head == NULL) { //if list is empty
			head = node;
		} else { //there elements in the list
			node->next = head;
			head = node;
		}
		n++; //increase the number of elements
	}
	void insert(int data, int index) {
		if (index < 0 || index >= n)
			throw exception();

		Node *node = new Node(data);
		if (head == NULL) {
			head = node;
		} else if (index == 0) {
			node->next = head;
			head = node;
		} else {
			Node *prevnode = find(index - 1);
			node->next = prevnode->next; //1
			prevnode->next = node; //2
		}
		n++; //increase the number of elements
	}
	void remove(int index) {
		if (index < 0 || index >= n)
			throw exception();
		Node *temp = head;
		if (index == 0) {
			temp = head;
			head = head->next;
		} else {
			Node *prevnode = find(index - 1);
			temp = prevnode->next;
			prevnode->next = temp->next; //prevnode->next->next;
		}
		delete temp;
		n--; //decrease the number of elements
	}

	int at(int index) { //int &at(int index)
		if (index < 0 || index >= n)
			throw exception();
		Node *temp = find(index);
		return temp->data;
	}


	void push_back(int data) {
		Node *node = new Node(data);
		if (head == NULL) { //if (head==0){
			head = node;
		} else {
			Node *temp = find(n-1); //find the last element
			temp->next = node;//append the new node
		}
		n++; //increase the number of elements
	}


	void clear(){
		Node *temp=head;
		Node *delnode;

		while(temp!=NULL){
			delnode=temp;
			temp=temp->next;
			delete delnode; // delete each node
		}
		head=NULL;//empty list
	}

	~SinglyLinkedList() { //destructor
		//delete nodes
		clear();
	}

	int length() {
		return n;
	}

	//count the elements one by one
	int length2() {
			int cnt = 0;
			Node *temp = head;
			while (temp != NULL) {
				cnt++;
				temp = temp->next;
			}
			return cnt;
	}
	void print(){
		for (int i = 0; i < n; i++)
				cout << "list.at(" << i << ") =" << at(i) << endl;

	}

};

int main() {
	SinglyLinkedList list;
	//Example push_front
	list.push_front(20);
	list.push_front(30);
	list.push_front(40);
	list.push_front(270);

	list.print();
	//Example insert
	list.insert(100, 2);
	list.insert(55, 0);
	cout<<"\nExample: list.insert(55, 0): "<<endl;
	list.print();

	//Example remove
	list.remove(1);
	cout << "\nExample: list.remove(1)" << endl;
	list.print();

	//Example push_back
	list.push_back(22);
	cout<<"\nExample: list.push_back(22): "<<endl;
	list.print();

	cout<<"\nlist.length() ="<<list.length()<<endl;
	cout<<"list.length2()="<<list.length2()<<endl;

	list.clear();
	cout<<"\nlist.clear():"<<endl;
	list.print();


	return 0;
}
