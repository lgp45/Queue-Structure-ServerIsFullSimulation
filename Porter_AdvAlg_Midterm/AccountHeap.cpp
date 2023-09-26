#include "AccountHeap.h"

//Output
void AccountHeap::PrintHeap()
{
	int i = 0;
	cout << "\nPrinting prio-heap\n";
	while (i <= size - 1)
	{
		cout << "\nAccount Name: " << Heap[i].GetAccountName() << "  ID: " << Heap[i].GetID();
		i++;
	}
}


//Control
int AccountHeap::Parent(int i)
{
	return (i - 1) / 2;
}
int AccountHeap::LeftChild(int i)
{
	return ((2 * i) + 1);
}
int AccountHeap::RightChild(int i)
{
	return ((2 * i) + 2);
}
void AccountHeap::ShiftUp(int i)
{
	while (i > 0 && Heap[Parent(i)].GetID() < Heap[i].GetID()) {
		swap(Heap[Parent(i)], Heap[i]);

		i = Parent(i);
	}
}
void AccountHeap::ShiftDown(int i)
{
	int maxIndex = i;
	//left child node
	int left = LeftChild(i);
	if (left <= size && Heap[i].GetID() > Heap[maxIndex].GetID())
	{
		maxIndex = left;
	}

	//right child node
	int right = RightChild(i);
	if (right <= size && Heap[right].GetID() > Heap[maxIndex].GetID())
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
void AccountHeap::Insert(Account p) 
{
	if (IsFull())
	{
		cout << "The heap is full.";
		return;
	}
	size = size + 1;
	Heap[size] = p;
	ShiftUp(size);
}
Account AccountHeap::ExtractMaxPrio() 
{
	if (IsEmpty())
	{
		cout << "The heap is empty.";
		return NULL;
	}
	//grab item 0 :: MAX
	Account result = Heap[0];

	Heap[0] = Heap[size];
	size = size - 1;
	//replace the root node value with the last leaf, to ensure Heap
	ShiftDown(0);
	//cout << "\nAfk Timer: " << to_string(result.character->m_TimeAfk) << "/" << to_string(result.character->m_MaxTimeAfk);
	//out the resulting item;
	return result;
}
void AccountHeap::ChangeAccountPriority(int i, Account p) 
{
	cout << "\nChanging item priority...Swapping " << i << " and " << p.GetID();
	Account oldp = Heap[i];
	Heap[i] = p;

	if (p.GetID() > oldp.GetID())
	{
		ShiftUp(i);
	}
	else
	{
		ShiftDown(i);
	}
}
Account AccountHeap::GetMaxPrio() 
{
	return Heap[0];
}
void AccountHeap::Remove(int i) 
{
	cout << "\nRemoving item: " << i << " from the heap.";
	Heap[i] = GetMaxPrio();

	//shift the node onto the root
	ShiftUp(i);


	ExtractMaxPrio();
}
void AccountHeap::FillAccountHeap()
{
	for (int i = 0; i < HEAP_SIZE; i++)
	{
		string t = "Player " + to_string(i);
		Account tester = Account(i, t);
		string c = "Character " + to_string(i);
		Player* t1 = new Player(c);
		t1->m_MaxTimeAfk = RandomRange(10, 60);
		tester.character = t1;
		Insert(tester);
	}
}
int AccountHeap::IsEmpty()
{
	return (size == 0);
}
int AccountHeap::IsFull()
{
	return size == HEAP_SIZE;
}
int AccountHeap::RandomRange(int _low, int _high)
{
	//srand(time(NULL));
	return rand() % ((_high - _low) + 1) + _low;
}