#include "Queue.h"

//member funcs

Queue* Queue::constructQueue(int capacity)
{
	Queue* queue = new Queue();
	queue->capacity = capacity;


	queue->back = capacity - 1;
	queue->set = new int[queue->capacity];
	return queue;
}

int Queue::IsFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

int Queue::IsEmpty(Queue* queue)
{
	return (queue->size == 0);
}

//add item into the queue, adjust the queue sizing for the new addition
void Queue::Enqueue(Queue* q, int itemToAdd)
{
	//if queue is at capacity, return out
	if (IsFull(q))
	{
		cout << "\nThe queue is currently full, please wait for items to be dequeued.";
		return;
	}

	//adjust the back and ensure we have the backest item
	q->back = (q->back + 1) % q->capacity;
	//cache the selected item location;
	q->set[q->back] = itemToAdd;
	//increment the queue size now that we have placed in a new item;
	q->size = q->size + 1;
	//output our item
	cout << "\nEnqueueing " << itemToAdd << ":: Position in Queue = " << q->back;
}

//func type is the type of the item object we are removing, if it was player it would be Player Dequeue.
int Queue::Dequeue(Queue* q)
{
	//if queue is empty just return out.
	if (IsEmpty(q))
	{
		cout << "\nThe queue is currently empty and no items available to be Dequeued.\n";
		return INT_MIN;
	}

	int removeItem = q->set[q->front];
	cout << "\nDequeueing " << removeItem << "Position in Queue = " << q->front;
	q->front = (q->front + 1) % q->capacity;
	q->size = q->size - 1;

	return removeItem;
}

//grabbing front item from the queue (also checks if empty)
int Queue::Front(Queue* q)
{
	if (IsEmpty(q))
	{
		cout << "\nThe queue is empty, no front item present.\n";
		return INT_MIN;
	}

	return q->set[q->front];
}

//grabbing back item from the queue (also checks if empty)
int Queue::Back(Queue* q)
{
	if (IsEmpty(q))
	{
		cout << "\nThe queue is empty, no back item present.\n";
		return INT_MIN;
	}
	return q->set[q->back];
}
