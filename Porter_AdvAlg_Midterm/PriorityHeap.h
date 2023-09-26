
#ifndef PRIORITYHEAP_H
#define PRIORITYHEAP_H
#include <iostream>
#include "Define.h";
using namespace std;
enum HeapType {minHeap, maxHeap };
class PriorityHeap
{
private:

public:
	int Heap[HEAP_SIZE];
	int size = -1;
	HeapType type;
	//Output
	void PrintHeap();

	//feature sets
	void SetHeapType(HeapType typeSet);
	HeapType GetHeapType();
	//Control
	int Parent(int i);
	int LeftChild(int i);
	int RightChild(int i);
	void ShiftUp(int i);
	void ShiftDown(int i);
	void Insert(int p);
	int ExtractMaxPrio();
	void ChangePriority(int i, int p);
	int GetMaxPrio();
	void Remove(int i);

};
#endif