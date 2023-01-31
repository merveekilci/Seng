//============================================================================
// Name        : bst_linked.cpp
// Description : Example Binary Search Tree -BST implementation
//============================================================================

#include <iostream>
#include <cmath>
#include<queue>
using namespace std;

class NotFoundException: public exception {
private:
	char *msj;
public:
	NotFoundException(char *msj = (char*) "Element not in the BST!") {
		this->msj = msj;
	}
	const char* what() const throw () {
		return msj;
	}
};


class Node {
public:
	int data;
	Node *left, *right;
	Node(const int &data, Node *left = NULL, Node *right = NULL) {
		this->data  = data;
		this->right = right;
		this->left  = left;
	}
};

class BST {
private:
	Node *root;//root node
	int count;

	void addnode(Node *&node, const int &data) {
		if (node == NULL)
			node = new Node(data);
		else if (data < node->data) {
			addnode(node->left, data);
		} else if (data > node->data) {
			addnode(node->right, data);
		} else
			return; //equal. The key already exist
	}


	Node *&findnode(Node *&node, const int &data) {
		if (node == NULL) throw NotFoundException();

		if (data == node->data) {
			return node;
		} else if (data < node->data) {
			findnode(node->left, data);
		} else //(data > node->data)
		{
			findnode(node->right, data);
		}
	}



	void levelorder(Node *node, int level) const {
		if (node == NULL)
			return;
		if (level == 0)
			cout << node->data << " ";
		else {
			levelorder(node->left, level - 1);
			levelorder(node->right, level - 1);
		}
	}

	void preorder(Node * node) {
	    if (node != NULL) {
	        cout << node->data << " ";
	        preorder(node->left);
	        preorder(node->right);
	    }
	}

	void inorder(Node * node) {
	    if (node != NULL) {
	        inorder(node->left);
	        cout << node->data << " ";
	        inorder(node->right);
	    }
	}
	void postorder(Node * node) {
		if (node != NULL) {
		    postorder(node->left);
		    postorder(node->right);
		    cout << node->data << " ";
		}
	}


public:
	BST() {//constructor
		root = NULL;//bst is empty
		count = 0;
	}

	bool empty() {
		return root == NULL;
	}
	void add(const int &data) {//driver function
		addnode(root, data);
		count++;
	}

	void remove(const int &data) {
		//find the node to be removed
		Node *&node = findnode(root, data);
		//make connections
		Node *temp = node;
		if (node->left == NULL) //one child case
			node = node->right;
		else if (node->right == NULL) //one child case
			node = node->left;
		else { //two child case
			   //find largest element of left subtree. Alternatively  find smallest element of right subtree
			temp = node->left;
			Node *parentnode = node;
			while (temp->right != NULL) { //find the rightmost element
				parentnode = temp;
				temp = temp->right;
			}
			//replace the data of the node to be removed
			node->data = temp->data;
			if (parentnode == node)
				node->left = temp->left;
			else
				parentnode->right = temp->left; //rightmost node may have a subtree on the left
		}
		delete temp;

		count--;
	}

	int height(Node *node) const {
		if (node == NULL)
			return -1;
		return 1 + max(height(node->left), height(node->right));
	}

//	int height(Node *node) const {
//			if (node == NULL)
//				return -1;
//			return 1 + max(-1), height(-1));
//		}

	void clear() {
		while (root != NULL)
			remove(root->data);
	}
	int size() {
		return count;
	}
	~BST() {
		clear();
	}
	void print_preorder(){
		cout<<"preorder traversal:"<<endl;
		preorder(root);
		cout<<endl;
	}
	void print_inorder(){
		cout<<"inorder traversal:"<<endl;
		inorder(root);
		cout<<endl;
	}
	void print_postorder(){
		cout<<"postorder traversal:"<<endl;
		postorder(root);
		cout<<endl;
	}
	void print_levelorder(){
		//iterative level order
		cout<<"\nlevelorder traversal:"<<endl;
	    queue<Node*> q;
	    Node *temp;
	    q.push(root);
	    while (!q.empty()) {
	        temp = q.front();
	        cout << temp->data << " ";
	        if (temp->left != NULL)
	            q.push(temp->left);
	        if (temp->right != NULL)
	            q.push(temp->right);
	        q.pop();
	    }
	    cout<<endl;
	}

	void print_levelorder2() {
		int h = height(root);
		for (int level = 0; level <= h; level++) {
			levelorder(root, level);
			cout << endl;
		}
	}

};

int main() {
	BST bst;

	bst.add(50);
	bst.add(20);
	bst.add(70);
	bst.add(30);
	bst.add(13);
	bst.add(65);
	bst.add(85);
	cout << "\nsize=" << bst.size() << endl;
	bst.print_preorder();
	bst.print_inorder();
	bst.print_postorder();
	bst.print_levelorder();


	bst.remove(70);

	cout << "\nsize=" << bst.size() << endl;
	bst.print_levelorder();

	bst.remove(85);

	cout << "\nsize=" << bst.size() << endl;
	bst.print_levelorder();

	bst.remove(20);

	cout << "\nsize=" << bst.size() << endl;
	bst.print_levelorder();


	return 0;
}
