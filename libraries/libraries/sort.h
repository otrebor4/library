#include <iostream>
#include <list>
#include <vector>
#include "Heap.h"
#include "pairKeyComp.h"
using namespace std;

template<class T>
list<T> sortKArrays( T ** arrays, int k, int size [])
{
	list<T> out;
	heap< pairKeyComp<T,pair<int,int>> > minHeap(k);
	for(int i = 0; i < k; i++)
	{
		pair<int,int> pos(i,0);
		pairKeyComp<T,pair<int,int> > pair(arrays[i][0], pos ); //add fist item from each array to the minheap
		minHeap.push(pair);
	}
	bool done = false;
	while(!minHeap.empty())
	{
		pairKeyComp<T,pair<int,int>> val = minHeap.pop();
		pair<int,int> pos = val.value;
		int l = pos.first;
		int i = pos.second+1;
		if(size[l] > i)
		{
			pos.first = l;
			pos.second = i;
			pairKeyComp<T,pair<int,int> > pair(arrays[l][i], pos);
			minHeap.push(pair);
		}
		out.push_back(val.key);
	}
	return out;
}