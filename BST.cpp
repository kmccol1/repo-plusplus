#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	Node() {
		this->left = nullptr;
		this->right = nullptr;
		//data = 0;
	}
	~Node();
	Node<T>& operator= (const Node&);
};

template <typename T>
class BST
{

	public:
		BST();
		~BST();
		Node<T>* insert(Node<T>*&, const T &);
		Node<T>* insert(const T&);
		Node<T>* getRoot(){ return root; } 
		Node<T>& operator= (const Node<T>&);
		void display(Node<T>*);
	private:
		Node<T>* root;
};



template <typename T>
Node<T>::~Node<T>()
{
	delete left;
	delete right;
}

template <typename T>
Node<T>* BST<T>::insert(const T& val)
{
	return insert(root, val);
}

template <typename T>
Node<T>& BST<T>::operator= (const Node<T>& temp)
{
	this->data = temp->data;
	this->left = temp->left;
	this->right = temp->right;

	return *this;
}

template <typename T>
void BST<T>::display(Node<T>* root)
{
	if (root != nullptr)
	{

		cout << root->data << endl;

		display(root->left);
		display(root->right);
	}
}

template <typename T>
BST<T>::BST()
{
	root = nullptr;
}

template <typename T>
BST<T>::~BST()
{
	delete root;
}

template <typename T>
Node<T>* BST<T>::insert(Node<T>* & root, const T & val)
{
	Node<T>* leaf;
	if (root == nullptr) //empty tree
	{
		cout << "Root is NULL" << endl;
		leaf = new Node<T>();
		leaf->data = val;
		leaf->left = leaf->right = nullptr;
		root = leaf;
	}

	else if (val < root->data)
		root->left = insert(root->left, val);
	else if (val > root->data)
		root->right = insert(root->right, val);

	return root;
}