#include <iostream>
#include <string>
#include <list>

#include "Heap.h"
#include "medianQueue.h"
#include "HashTable.h"
#include "sort.h"
using namespace std;

void testKList();

void testMedia();

int main()
{
	hashTable<string,int> table;
	table.put("one",1);
	table.put("two",2);
	cout << table.get("two") << " " << table.get("one");
	system("pause");
	return 0;
}

void testMedia()
{
	heap<int> minHeap;
	medianQueue<int> media;
	media.insert(1);
	media.insert(100);
	media.insert(3);
	media.insert(4);
	media.insert(2);
	media.insert(50);
	media.insert(14);
	media.insert(30);
	media.insert(20);
	media.insert(2);
	media.insert(0);

	minHeap.push(1);
	minHeap.push(100);
	minHeap.push(3);
	minHeap.push(4);
	minHeap.push(2);
	minHeap.push(50);
	minHeap.push(14);
	minHeap.push(30);
	minHeap.push(20);
	minHeap.push(2);
	minHeap.push(0);
	while(!minHeap.empty())
	{
		cout << minHeap.pop() << "  ";
	}
	cout << "\n";
	while(!media.empty())
	{
		cout << media.extractMedian() << "\n";
		system("pause");
	}
}

void testKList()
{
	int const k = 30;
	int size[k];
	int ** arrays = new int*[k];

	//create k sorted arrays
	for(int i = 0; i < k; i++)
	{
		size[i] = rand()%100;
		arrays[i] = new int[size[i]];
		int start = rand()%25;
		for(int j = 0; j < size[i]; j++)
		{
			arrays[i][j] = start;
			start += rand()%5+1;
		}
	}

	list<int> sortList = sortKArrays<int>(arrays,k,size);
	

	system("pause");

}