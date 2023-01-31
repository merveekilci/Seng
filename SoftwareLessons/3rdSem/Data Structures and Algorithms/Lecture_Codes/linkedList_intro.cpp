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

int get(Node *head, int inx) { //return data (int)
	Node *temp = head;
	int c = 0;
	while (temp != NULL) {
		if (c == inx)
			break;
		temp = temp->next;
		c++;
	}
	return temp->data;
}

void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout <<"\ttemp->data=" << temp->data << endl;
		temp = temp->next;
	}
}

/***
 * Find the number of elements in a given list
 */
int length(Node *head) {
	Node *temp = head;
	int c = 0;
	while (temp != NULL) {
		temp = temp->next;
		c++;
	}
	return c; //return the number of elements
}

int main() {
	Node *head = NULL; //
	Node *node1 = new Node(10); // item 0
	head = node1;
	Node *node2 = new Node(12); // item 1
	Node *node3 = new Node(17); // item 2
	Node *node4 = new Node(23); // item 3
	Node *node5 = new Node(43); // item 3
	Node *node6 = new Node(77); // item 3
	//	cout<<"&node1"<<&node1<<endl;
	//	cout<<"&node2"<<&node2<<endl;
	//	cout<<"&node3"<<&node3<<endl;
	//	cout<<"&node4"<<&node4<<endl;
	// item 0 -> item 1 -> item 2 -> item 3 -> NULL
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = NULL;

	cout << "print elements -1:" << endl;
	print(head);
	cout << "\nprint elements -2:" << endl;
	int N=length(head);
	for (int i=0;i<N;i++)
		cout << "\tget("<<i<<")=" << get(head, i) << endl; // print specific element

	return 0;
}
