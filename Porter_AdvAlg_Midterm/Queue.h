#include <iostream>
using namespace std;
class Queue
{

public:
	//member vars
	int front, back, size;	
	unsigned int capacity;	//ensure positive capacity allowance
	int *set;

	//member funcs
	//constructor
	Queue* constructQueue(int capacity);

	//Checks
	int IsFull(Queue* queue);
	int IsEmpty(Queue* queue);

	//Controls
	//add item into the queue, adjust the queue sizing for the new addition
	void Enqueue(Queue* q, int itemToAdd);
	//func type is the type of the item object we are removing, if it was player it would be Player Dequeue.
	int Dequeue(Queue* q);

	//Accesors
	//grabbing front item from the queue (also checks if empty)
	int Front(Queue* q);
	//grabbing back item from the queue (also checks if empty)
	int Back(Queue* q);

};