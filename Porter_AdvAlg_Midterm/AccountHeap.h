
#ifndef ACCOUNTHEAP_H
#define ACCOUNTHEAP_H
#include <iostream>
#include "Define.h"
#include "Account.h"
#include <string>
#include <vector>
using namespace std;

class AccountHeap
{
private:

public:
	//Account Heap[HEAP_SIZE];
	vector<Account> Heap;
	int size = -1;

	//Output
	void PrintHeap();

	//Testing
	void FillAccountHeap();
	int IsFull();
	int IsEmpty();
	//Control
	int Parent(int i);
	int LeftChild(int i);
	int RightChild(int i);
	void ShiftUp(int i);
	void ShiftDown(int i);
	void Insert(Account p);
	Account ExtractMaxPrio();
	void ChangeAccountPriority(int i, Account p);
	Account GetMaxPrio();
	void Remove(int i);
	int RandomRange(int _low, int _high);


};
#endif