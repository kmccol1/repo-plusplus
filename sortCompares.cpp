#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
using namespace std;
#include "results.h"

void getData(int list[], int size, const char fileName[]);

void insertSort(int list[], int size, int& comp, int& cpy);
void selectSort(int list[], int size, int& comp, int& cpy);
void bubbleSort(int list[], int size, int& comp, int& cpy);
void shellSort(int list[], int size, int& comp, int& cpy);
void heapSort(int list[], int size, int& comp, int& cpy);

void _siftUp(int list[], int child, int& comp, int& cpy);
void _siftDown(int list[], int parent, int heapSize, int& comp, int& cpy); 
void quickSort(int list[], int size, int& comp, int& cpy);
void _quickSort(int list[], int left, int right, int& comp, int& cpy);
void putMedianLeft(int list[], int left, int right, int& comp, int& cpy);
int partition(int list[], int left, int right, int& comp, int& cpy);

void calcResults(Results& result);
void displayResults(Results iResults, Results sResults, Results bResults,
	Results shResults, Results hResults, Results qResults);

int main()
{
	const int NUM_ELEMENTS = 1000;

	int ordered[NUM_ELEMENTS],
		unordered[NUM_ELEMENTS],
		reversed[NUM_ELEMENTS];

	Results iResults,
		    sResults,
		    bResults,
		    shResults,
		    hResults,
		    qResults;

	getData(ordered, NUM_ELEMENTS, "ordered.txt");
	getData(unordered, NUM_ELEMENTS, "unordered.txt");
	getData(reversed, NUM_ELEMENTS, "reversed.txt");

	insertSort(ordered, NUM_ELEMENTS,iResults.ordCompares, iResults.ordCopies );
	insertSort(unordered, NUM_ELEMENTS,iResults.unOrdCompares, iResults.unOrdCopies );
	insertSort(reversed, NUM_ELEMENTS, iResults.revOrdCompares, iResults.revOrdCopies );
	calcResults(iResults);

	getData(ordered, NUM_ELEMENTS, "ordered.txt");
	getData(unordered, NUM_ELEMENTS, "unordered.txt");
	getData(reversed, NUM_ELEMENTS, "reversed.txt");

	selectSort(ordered, NUM_ELEMENTS, sResults.ordCompares, sResults.ordCopies);
	selectSort(unordered, NUM_ELEMENTS, sResults.unOrdCompares, sResults.unOrdCopies);
	selectSort(reversed, NUM_ELEMENTS, sResults.revOrdCompares, sResults.revOrdCopies);
	calcResults(sResults);

	getData(ordered, NUM_ELEMENTS, "ordered.txt");
	getData(unordered, NUM_ELEMENTS, "unordered.txt");
	getData(reversed, NUM_ELEMENTS, "reversed.txt");

	bubbleSort(ordered, NUM_ELEMENTS, bResults.ordCompares, bResults.ordCopies);
	bubbleSort(unordered, NUM_ELEMENTS, bResults.unOrdCompares, bResults.unOrdCopies);
	bubbleSort(reversed, NUM_ELEMENTS, bResults.revOrdCompares, bResults.revOrdCopies);
	calcResults(bResults);

	getData(ordered, NUM_ELEMENTS, "ordered.txt");
	getData(unordered, NUM_ELEMENTS, "unordered.txt");
	getData(reversed, NUM_ELEMENTS, "reversed.txt");

	shellSort(ordered, NUM_ELEMENTS, shResults.ordCompares, shResults.ordCopies);
	shellSort(unordered, NUM_ELEMENTS, shResults.unOrdCompares, shResults.unOrdCopies);
	shellSort(reversed, NUM_ELEMENTS, shResults.revOrdCompares, shResults.revOrdCopies);
	calcResults(shResults);

	getData(ordered, NUM_ELEMENTS, "ordered.txt");
	getData(unordered, NUM_ELEMENTS, "unordered.txt");
	getData(reversed, NUM_ELEMENTS, "reversed.txt");

	heapSort(ordered, NUM_ELEMENTS, hResults.ordCompares, hResults.ordCopies);
	heapSort(unordered, NUM_ELEMENTS, hResults.unOrdCompares, hResults.unOrdCopies);
	heapSort(reversed, NUM_ELEMENTS, hResults.revOrdCompares, hResults.revOrdCopies);
	calcResults(hResults);

	getData(ordered, NUM_ELEMENTS, "ordered.txt");
	getData(unordered, NUM_ELEMENTS, "unordered.txt");
	getData(reversed, NUM_ELEMENTS, "reversed.txt");

	quickSort(ordered, NUM_ELEMENTS, qResults.ordCompares, qResults.ordCopies);
	quickSort(unordered, NUM_ELEMENTS, qResults.unOrdCompares, qResults.unOrdCopies);
	quickSort(reversed, NUM_ELEMENTS, qResults.revOrdCompares, qResults.revOrdCopies);
	calcResults(qResults);

	//11k as of 4/30

	displayResults(iResults, sResults, bResults, shResults, hResults, qResults);

	return 0;
}

void getData(int list[], int size, const char fileName[])
{
	int count;
	ifstream fin(fileName);

	count = 0;

	while ((count < size) && (fin >> (list[count])))
		count += 1;

	fin.close();
}

void insertSort(int list[], int size, int& comp, int& cpy)
{
	int hold,
		j;

	for (int i = 1; i < size; i++)
	{
		hold = list[i];
		cpy++;

		for (j = (i - 1); (j >= 0) && (++comp) && (list[j] > hold); j--)
		{
			list[j + 1] = list[j];
			cpy++;
		}

		list[j + 1] = hold;
		cpy++;
	}

}
void selectSort(int list[], int size, int& comp, int& cpy)
{
	int minIndex;

	for (int i = 0; i < (size - 1); i++)
	{
		minIndex = i;

		for (int j = (i + 1); j < size; j++)
		{
			if (( ++ comp ) && (list[j] < list[minIndex]))
				minIndex = j;
		}

		swap(list[minIndex], list[i]);
		cpy += 3;
	}
}

void bubbleSort(int list[], int size, int& comp, int& cpy)
{
	bool didSwap;
	didSwap = true;

	for (int i = 0; (i < (size - 1)) && (didSwap == true); i++)
	{
		didSwap = false;

		for (int j = (size - 1); j > i; j--)
		{
			
			if ( (++comp) && (list[j] < list[j - 1]))
			{
				swap(list[j], list[j - 1]);
				cpy += 3;
				didSwap = true;
			}
		}
	}
}

void shellSort(int list[], int size, int& comp, int& cpy)
{
	int hold,
		i,
		j;

	for (int gap = (size / 2); gap >= 10; gap /= 2 )
	{
		if (gap % 2 == 0)
			gap++;

		for (int i = gap; (i < size); i++)
		{
			hold = list[i];
			cpy++;

			for (j = (i - gap); (j >= 0) && (++comp) && (list[j] > hold); j -= gap)
			{
				list[j + gap] = list[j];
				cpy++;
			}

			list[j + gap] = hold;
			cpy++;
		}
	}

	insertSort(list, size, comp, cpy);	
}

void heapSort(int list[], int size, int& comp, int& cpy)
{
	for (int i = 1; i < size; i++)
	{
		_siftUp(list, i, comp, cpy);
	}

	for (int i = size - 1; i > 0; i--)
	{
		swap(list[0], list[i]);
		cpy += 3;
		_siftDown(list, 0, i, comp, cpy);
	}
}

void _siftUp(int list[], int child, int& comp, int& cpy)
{
	int parent;

	if (child > 0)
	{
		parent = (child - 1) / 2;

		comp++;

		if (list[child] > list[parent])
		{
			swap(list[child], list[parent]);
			cpy += 3;
			_siftUp(list, parent, comp, cpy);
		}
	}
}

void _siftDown(int list[], int parent, int heapSize, int& comp, int& cpy)
{
	int child;
	child = (2 * parent) + 1;

	if (child < heapSize)
	{
		if ( ( ( child + 1) < heapSize ) && (++comp) && ( list [ child ] < list [ child + 1 ] ) )
			child++;

		comp++;

		if (list[parent] < list[child])
		{
			swap(list[parent], list[child]);
			cpy += 3;
			_siftDown(list, child, heapSize, comp, cpy);
		}
	}
}

void quickSort(int list[], int size, int& comp, int& cpy)
{
	_quickSort(list, 0, (size - 1), comp, cpy);
	insertSort(list, size, comp, cpy);
}

void _quickSort(int list[], int left, int right, int& comp, int& cpy)
{
	int pivotPt;

	putMedianLeft(list, left, right, comp, cpy);
	if (left < right)
	{
		pivotPt = partition(list, left, right, comp, cpy);

		_quickSort(list, left, pivotPt - 1, comp, cpy);
		_quickSort(list, pivotPt + 1, right, comp, cpy);
	}

}

void putMedianLeft(int list[], int left, int right, int& comp, int& cpy)
{
	int mid;
	mid = (left + right) / 2;

	if (list[left] < list[mid])
	{
		swap(list[left], list[mid]);
		cpy += 3;
	}

	if (list[mid] > list[right])
	{
		swap(list[mid], list[right]);
		cpy += 3;
	}

	if (list[left] > list[right])
	{
		swap(list[left], list[right]);
		cpy += 3;
	}

	comp += 3;

}
int partition(int list[], int left, int right, int& comp, int& cpy)
{
	int lte, gt, pivot;

	lte = left + 1;
	gt = right;
	pivot = left;

	while (lte < gt)
	{
		lte = pivot + 1;

		while ((lte < gt) && (++comp) && list[lte] > list[pivot])
			lte++;

		while ((gt > lte) && (++comp) && list[gt] > list[pivot])
			gt--;

		if (pivot + 1 <= right)
		{

			if (list[lte] <= list[pivot])
			{
				swap(list[pivot], list[pivot + 1]);

				if (pivot + 1 != lte)
				{

				}

				pivot++;
			}
			if (list[gt] < list[pivot])
			{
				swap(list[pivot], list[pivot + 1]);
				//cpy += 3;

				if (pivot + 1 != gt)
				{
					swap(list[gt], list[pivot]);
				}

				pivot++;
			}
		}
	}

	return gt;
}


void calcResults(Results& result)
{
	const int NUM_SORTS = 3;

	int totalCompares,
		totalCopies;

	totalCompares = 0;
	totalCopies = 0;

	totalCompares += result.ordCompares + result.unOrdCompares + result.revOrdCompares;
	totalCopies += result.ordCopies + result.unOrdCopies + result.revOrdCopies;


	result.avgCompares = round((double)(totalCompares) / NUM_SORTS);
	result.avgCopies = round((double)(totalCopies) / NUM_SORTS);
}

void displayResults(Results iResults, Results sResults, Results bResults,
	Results shResults, Results hResults, Results qResults)
{
	cout << setw(55) << "Compares / Copies";
	cout << "\nSorts" << setw(20) << "Ordered List" << setw(30) << "Unordered List"
		<< setw(25) << "Reversed List" << setw(15) << "Average";

	//print sort data, insert,select,bubble,shell,heap,quik,etc
	//formatting is eh
	cout << endl;
	cout << "\nInsert" << setw(10) << iResults.ordCompares << " / " << iResults.ordCopies
		 << setw(24) << iResults.unOrdCompares << " / " << iResults.unOrdCopies
		 << setw(15) << iResults.revOrdCompares << " / " << iResults.revOrdCopies
		 << setw(10) << iResults.avgCompares << " / " << iResults.avgCopies;

	cout << endl;
	cout << "\nSelect" << setw(10) << sResults.ordCompares << " / " << sResults.ordCopies
		<< setw(24) << sResults.unOrdCompares << " / " << sResults.unOrdCopies
		<< setw(17) << sResults.revOrdCompares << " / " << sResults.revOrdCopies
		<< setw(12) << sResults.avgCompares << " / " << sResults.avgCopies;

	cout << endl;
	cout << "\nBubble" << setw(10) << bResults.ordCompares << " / " << bResults.ordCopies
		<< setw(27) << bResults.unOrdCompares << " / " << bResults.unOrdCopies
		<< setw(15) << bResults.revOrdCompares << " / " << bResults.revOrdCopies
		<< setw(9) << bResults.avgCompares << " / " << bResults.avgCopies;

	cout << endl;
	cout << "\nShell" << setw(11) << shResults.ordCompares << " / " << shResults.ordCopies
		<< setw(23) << shResults.unOrdCompares << " / " << shResults.unOrdCopies
		<< setw(16) << shResults.revOrdCompares << " / " << shResults.revOrdCopies
		<< setw(11) << shResults.avgCompares << " / " << shResults.avgCopies;

	cout << endl;
	cout << "\nHeap" << setw(12) << hResults.ordCompares << " / " << hResults.ordCopies
		<< setw(23) << hResults.unOrdCompares << " / " << hResults.unOrdCopies
		<< setw(16) << hResults.revOrdCompares << " / " << hResults.revOrdCopies
		<< setw(11) << hResults.avgCompares << " / " << hResults.avgCopies;

	cout << endl;
	cout << "\nQuick" << setw(12) << qResults.ordCompares << " / " << qResults.ordCopies
		<< setw(23) << qResults.unOrdCompares << " / " << qResults.unOrdCopies
		<< setw(16) << qResults.revOrdCompares << " / " << qResults.revOrdCopies
		<< setw(11) << qResults.avgCompares << " / " << qResults.avgCopies;

}
