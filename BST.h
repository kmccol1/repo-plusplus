

#ifndef BST_H
#define BST_H

//****************************************************************************************************

#include <algorithm>
#include "Node.h"

//****************************************************************************************************

template < typename T >
class BST
{
	private:
		Node < T > * root;

		void _destructor ( Node < T > * pRoot );
		Node < T > * _retrieve ( Node < T > * pRoot , const T & dataOut ) const;
		Node < T > * _insert ( Node < T > * pRoot , const T & dataIn );
		Node < T > * _remove ( Node < T > * pRoot , const T & dataOut );
		void _inorderTraverse ( Node < T > * pRoot ,  void ( * displayStudent ) ( const T & stu ) ) const;


	public:
		BST ( );
	       ~BST ( );

		bool retrieve ( T & dataOut ) const;
		bool insert ( const T & dataIn );
		bool remove ( T & dataOut );
		bool update ( const T & dataIn );
		void inorderTraverse ( void ( * displayStudent ) ( const T & stu ) ) const;

};

//****************************************************************************************************

template < typename T >
BST < T > :: BST ( )
{
	root = nullptr;
}

//****************************************************************************************************

template < typename T >
BST < T > :: ~BST ( )
{
	_destructor ( root );
}

//****************************************************************************************************

template < typename T >
void BST < T > :: _destructor ( Node < T > * pRoot )
{
	if ( pRoot != nullptr )
	{
		_destruct ( pRoot -> left );
		_destruct ( pRoot -> right );

		delete pRoot;
		pRoot = nullptr;
	}
}

//****************************************************************************************************

template < typename T >
bool BST < T > :: retrieve ( T & dataOut ) const
{
	bool success = false;

	Node < T > * pFound;

	pFound = _retrieve ( root , dataOut );

	if ( pFound != nullptr )
	{
		dataOut = pFound -> data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template < typename T >
Node < T > * BST < T > :: _retrieve ( Node < T > * pRoot , const T & dataOut ) const
{
	if ( pRoot != nullptr )
	{
		if ( pRoot -> data > dataOut )
			pRoot = _retrieve ( pRoot -> left , dataOut );
		else if ( pRoot -> data < dataOut )
			pRoot = _retrieve ( pRoot -> right , dataOut );
	}

	return pRoot;
}

//****************************************************************************************************

template < typename T >
bool BST < T > :: insert ( const T & dataIn )
{
	bool success = false;

	Node < T > * pFound;

	pFound = _retrieve ( root , dataIn );

	if ( pFound == nullptr )
	{
		root = _insert ( root , dataIn );
		success = true;
	}

	return success;
}

//****************************************************************************************************

template < typename T >
Node < T > * BST < T > :: _insert ( Node < T > * pRoot , const T & dataIn )
{
	if ( pRoot != nullptr )
	{
		if ( pRoot -> data > dataIn )
			pRoot -> left = _insert ( pRoot -> left , dataIn );
		else if ( pRoot -> data < dataIn )
			pRoot -> right = _insert ( pRoot -> right , dataIn );
	}
	else
		pRoot = new ( nothrow ) Node < T > ( dataIn );

	return pRoot;
}

//****************************************************************************************************

template < typename T >
bool BST < T > :: remove ( T & dataOut )
{
	bool success = false;

	Node < T > * pFound;

	pFound = _retrieve ( root , dataOut );

	if ( pFound != nullptr )
	{
		dataOut = pFound -> data;
		root = _remove ( pFound , dataOut );
		success = true;
	}

	return success;
}

//****************************************************************************************************

template < typename T >
Node < T > * BST < T > :: _remove ( Node < T > * pRoot , const T & dataOut )
{
	Node < T > * pMax,
			   * pDel;

	if ( pRoot != nullptr )
	{
		if ( pRoot -> data > dataOut )
			pRoot -> left = _remove ( pRoot -> left , dataOut );
		else if ( pRoot -> data < dataOut )
			pRoot -> right = _remove ( pRoot -> right , dataOut );
		else
		{
			if ( ( pRoot -> left != nullptr ) && ( pRoot -> right != nullptr ) )
			{
				pMax = pRoot -> left;

				pDel = pMax;

				while ( ( pDel -> right ) != nullptr )
				{
					pMax = pDel;
					pDel = pDel -> next;
				}

				if ( ( pMax -> right ) != nullptr )
					pMax = pMax -> right;

				pRoot -> data = pMax -> data;
				pRoot -> left = _remove ( pRoot -> left , pMax -> data );
				
			}
			else
			{
				pDel = pRoot;

				if ( ( pRoot -> left ) != nullptr )
					pRoot = pRoot -> left;
				else
					pRoot = pRoot -> right;

				delete pDel;
			}
		}
	}

	return pRoot;
}

//****************************************************************************************************

template < typename T >
bool BST < T > :: update ( const T & dataIn )
{
	bool success = false;

	Node < T > * pFound;

	pFound = _retrieve ( root , dataIn );

	if ( pFound != nullptr )
	{
		pFound -> data = dataIn;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template < typename T >
void BST < T > :: inorderTraverse ( void ( * displayStudent ) ( const T & stu ) ) const
{
	_inorderTraverse ( root , displayStudent );
}

//****************************************************************************************************

template < typename T >
void BST < T > :: _inorderTraverse ( Node < T > * pRoot , void ( * displayStudent ) ( const T & stu ) ) const
{
	if ( pRoot != nullptr )
	{
		_inorderTraverse ( pRoot->left , displayStudent );
		displayStudent ( pRoot -> data );
		_inorderTraverse ( pRoot -> right , displayStudent );
	}
}

//****************************************************************************************************

template < typename T >
int BST < T > :: _getCount ( Node < T > * pRoot ) const
{
	int result = 0;

	if ( pRoot != nullptr )
		result = 1 + ( ( _getCount ( pRoot -> left ) ) + ( _getCount ( pRoot -> right ) ) );

	return result;
}

//****************************************************************************************************

template < typename T >
bool BST < T > :: isEmpty ( ) const
{
	bool empty = true;
	
	if ( root != nullptr )
		empty = false;
	
	return empty;
}

//****************************************************************************************************

template < typename T >
bool BST < T > :: isFull ( ) const
{
	bool full = false;

	Node < T > * pTemp;

	pTemp = new ( nothrow ) Node < T >;

	if ( pTemp != nullptr )
	{
		full = false;
		delete pTemp;
		pTemp = nullptr;
	}
	else
		full = true;

	return full;
}

//****************************************************************************************************

#endif
