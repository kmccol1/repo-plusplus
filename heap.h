
#ifndef HEAP_H
#define HEAP_H

//****************************************************************************************************

#include <utility>
#include <new>

//****************************************************************************************************

template < typename T >
class Heap
{
	private:
		T * heap;
		int capacity;
		int numValues;

		void _siftUp ( int child );
		void _siftDown ( int parent );
		int _leftChildOf ( int parent ) const;
		int _parentOf ( int child ) const;

	public:
		Heap ( int cap = 100 );
		~Heap ( );
		bool insert (const T & dataIn );
		bool remove ( T & dataOut );
		bool viewMax ( T & dataOut ) const;
		int getCapacity ( ) const;
		int getNumValues ( ) const;
		bool isEmpty ( ) const;
		bool isFull ( ) const;

};

//****************************************************************************************************

template < typename T >
Heap < T > :: Heap ( int cap )
{
	const int MIN_CAP = 2;

	if ( cap >= MIN_CAP )
		capacity = cap;
	else
		capacity = MIN_CAP;

	heap = new ( nothrow ) T [ capacity ];
	numValues = 0;
}

//****************************************************************************************************

template < typename T >
Heap < T > :: ~Heap ( )
{
	delete [ ] heap;
	heap = nullptr;
	numValues = 0;
	capacity = 0;
}

//****************************************************************************************************

template < typename T >
int Heap < T > :: _leftChildOf ( int parent ) const
{
	int left;

	left = 2 * parent + 1;

	return left;
}

//****************************************************************************************************

template < typename T >
int Heap < T > :: _parentOf ( int child ) const
{
	int parent;

	parent = ( child - 1 ) / 2;

	return parent;
}

//****************************************************************************************************

template < typename T >
bool Heap < T > :: insert ( const T & dataIn )
{
	bool success = false;

	if ( numValues < capacity )
	{
		heap [ numValues ] = dataIn;
		_siftUp ( numValues );
		numValues ++;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template < typename T >
void Heap < T > :: _siftUp ( int child )
{
	int parent;

	if ( child > 0 )
	{
		parent = _parentOf ( child );

		if ( heap [ child ] > heap [ parent ] )
		{
			std :: swap ( heap [ parent ] , heap [ child ] );
			_siftUp ( parent );
		}
	}
}

//****************************************************************************************************

template < typename T >
bool Heap < T > :: remove ( T & dataOut)
{
	bool success = false;

	if ( numValues > 0 )
	{
		dataOut = heap [ 0 ];
		heap [ 0 ] = heap [ numValues - 1 ];
		numValues --;
		_siftDown ( 0 );
		success = true;
	}

	return success;
}

//****************************************************************************************************

template < typename T >
void Heap < T > :: _siftDown ( int parent )
{
	int child;

	child = _leftChildOf ( parent );

	if ( child < numValues )
	{
		if ( ( (child + 1) < numValues ) && ( heap [ child + 1 ] > heap [ child ]))
			child ++;
	}

	if ( heap [ child ] > heap [ parent ] )
	{
		std :: swap ( heap [ child ] , heap [ parent ] );
		_siftDown ( child );
	}
}

//****************************************************************************************************


template < typename T >
bool Heap < T > :: viewMax (T & dataOut ) const
{
	bool success = false;

	if ( numValues > 0 )
	{
		dataOut = heap [ 0 ];
		success = true;
	}

	return success;
}

//****************************************************************************************************

template < typename T >
int Heap < T > :: getCapacity ( ) const
{
	return capacity;
}

//****************************************************************************************************

template < typename T >
int Heap < T > :: getNumValues ( ) const
{
	return numValues;
}

//****************************************************************************************************

template < typename T >
bool Heap < T > :: isEmpty ( ) const
{
	return ( numValues == 0 );
}

//****************************************************************************************************

template < typename T >
bool Heap < T > :: isFull ( ) const
{
	return ( numValues == capacity );
}

//****************************************************************************************************

#endif
