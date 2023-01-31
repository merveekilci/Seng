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

int get(Node* head, int inx) { //return data (int)
    Node* temp = head;
    //...???
    int count = 0;
    while (temp != NULL) {
        if (count == inx)
            return (temp->data);
        count++;
        temp = temp->next;
    }

}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    
    cout << "get(4)=" << get(head, 4) << endl; // print specific element
    
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

	print(head);	//print elements

	cout << "get(4)=" << get(head, 4) << endl; // print specific element

	return 0;
}
