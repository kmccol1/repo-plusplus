#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node < T > * left;
	Node < T > * right;
	
	
	Node ( );
	~Node ( );
	Node < T > & operator= (const Node < T > & lhs);
};

template <typename T>
class BST
{
	private:
		Node < T > * root;

	public:
		BST ( );
		~BST ( );
		Node < T > * insert ( const Node < T > * data );
		Node < T > * insert ( const T & dataIn );
	
		Node < T > & operator= ( const Node <T> * rhs );
	
		void display ( );

};

template < typename T > 
Node < T > :: Node ( )
{
	data = 0;
	this -> left = nullptr;
	this -> right = nullptr;
}

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
	if (root == nullptr)
	{
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
