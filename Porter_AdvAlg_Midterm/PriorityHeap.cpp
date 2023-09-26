#include "PriorityHeap.h"

//returns the index of the parent node of a given node (input)
int PriorityHeap::Parent(int i) 
{
	return (i - 1) / 2;
}
//returns the index of the Left Child node of a given node (input)
int PriorityHeap::LeftChild(int i) 
{
	return ((2 * i) + 1);
}
//returns the index of the Right Child node of a given node (input)
int PriorityHeap::RightChild(int i) 
{
	return ((2 * i) + 2);
}
//shifts up a node to ensure heap mechanism
void PriorityHeap::ShiftUp(int i) 
{
	if (GetHeapType() == HeapType::minHeap || GetHeapType() == NULL)
	{
		while (i > 0 && Heap[Parent(i)] > Heap[i]) {
			swap(Heap[Parent(i)], Heap[i]);

			i = Parent(i);
		}
	}
	if(GetHeapType() == HeapType::maxHeap)
	{
		while (i > 0 && Heap[Parent(i)] < Heap[i]) {
			swap(Heap[Parent(i)], Heap[i]);

			i = Parent(i);
		}
	}

}
//shifts down a node to ensure heap mechanism
void PriorityHeap::ShiftDown(int i) 
{
	if (GetHeapType() == HeapType::minHeap || GetHeapType() == NULL)
	{
		int maxIndex = i;

		//left child node
		int left = LeftChild(i);
		if (left <= size && Heap[i] < Heap[maxIndex])
		{
			maxIndex = left;
		}

		//right child node
		int right = RightChild(i);

		if (right <= size && Heap[right] < Heap[maxIndex])
		{
			maxIndex = right;
		}

		//if i is not == maxIndex, swap them and shift the prior top downward
		if (i != maxIndex)
		{
			swap(Heap[i], Heap[maxIndex]);
			ShiftDown(maxIndex);	//calls itself again to ensure maxIndex is correct (recursion)
		}
	}
	if (GetHeapType() == HeapType::maxHeap)
	{
		int maxIndex = i;

		//left child node
		int left = LeftChild(i);
		if (left <= size && Heap[i] > Heap[maxIndex])
		{
			maxIndex = left;
		}

		//right child node
		int right = RightChild(i);
		if (right <= size && Heap[right] > Heap[maxIndex])
		{
			maxIndex = right;
		}

		//if i is not == maxIndex, swap them and shift the prior top downward
		if (i != maxIndex)
		{
			swap(Heap[i], Heap[maxIndex]);
			ShiftDown(maxIndex);	//calls itself again to ensure maxIndex is correct (recursion)
		}
	}
	
}
//insert a new item
void PriorityHeap::Insert(int p) 
{

	size = size + 1;
	Heap[size] = p;

	//sift up to ensure heap mech, cycles items
	ShiftUp(size);
}

//grabs the max item, our prio item;
int PriorityHeap::ExtractMaxPrio() 
{
	//grab item 0 :: MAX
	int result = Heap[0];

	Heap[0] = Heap[size];
	size = size - 1;
	//replace the root node value with the last leaf, to ensure Heap
	ShiftDown(0);
	//out the resulting item;
	return result;
}

//allows the change of priority of items
void PriorityHeap::ChangePriority(int i, int p) 
{
	cout << "\nChanging item priority...Swapping " << i << " and " << p;
	int oldp = Heap[i];
	Heap[i] = p;

	if (p > oldp)
	{
		ShiftUp(i);
	}
	else
	{
		ShiftDown(i);
	}
}

//return the max item
int PriorityHeap::GetMaxPrio() 
{
	return Heap[0];
}

//remove item from the heap
void PriorityHeap::Remove(int i) 
{
	cout << "\nRemoving item: " << i << " from the heap.";
	Heap[i] = GetMaxPrio() + 1;
	
	//shift the node onto the root
	ShiftUp(i);
	

	ExtractMaxPrio();
}


//feature set
void PriorityHeap::SetHeapType(HeapType typeSet)
{
	type = typeSet;
}
HeapType PriorityHeap::GetHeapType()
{
	return type;
}
//OUTPUTS
void PriorityHeap::PrintHeap()
{
	int i = 0;
	cout << "\nPrinting prio-heap\n";
	while(i <= size)
	{
		cout << Heap[i] << "  ";
		i++;
	}
}