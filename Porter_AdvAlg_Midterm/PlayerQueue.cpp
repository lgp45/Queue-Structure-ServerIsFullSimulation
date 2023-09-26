#include "PlayerQueue.h";

PlayerQueue* PlayerQueue::constructQueue(int capacity)
{
	cout << "Constructing player queue...";
	PlayerQueue* q = new PlayerQueue();
	const int se = capacity;

	q->set.resize(capacity);
	q->capacity = capacity;
	q->back = capacity - 1;
	return q;
}
void PlayerQueue::Enqueue(PlayerQueue* q, Player* itemToAdd)
{
	//if queue is at capacity, return out
	if (IsFull(q))
	{
		cout << "\nThe queue is currently full, please wait for items to be dequeued.";
		return;
	}

	//adjust the back and ensure we have the backest item
	q->back = (q->back + 1) % q->capacity;
	//itemToAdd->m_activeTimer = //random range;
	//cache the selected item location;
	q->set[q->back] = itemToAdd;
	//increment the queue size now that we have placed in a new item;
	q->size = q->size + 1;
	
	//output our item
	cout << "\nEnqueueing || \tPlayer: " << itemToAdd->m_name << "\tPosition in Queue = " << (q->size-1) << " / " << (q->size);
}
//func type is the type of the item object we are removing, if it was player it would be Player Dequeue.
Player* PlayerQueue::Dequeue(PlayerQueue* q)
{
	//if queue is empty just return out.
	if (IsEmpty(q))
	{
		cout << "\nThe queue is currently empty and no items available to be Dequeued.\n";
		return NULL;
	}

	Player *removeItem = q->set[q->front];
	

	q->front = (q->front + 1) % q->capacity;
	q->size = q->size - 1;
	cout << "\nDequeueing ||\tPlayer: " << removeItem->m_name;

	return removeItem;
}
int PlayerQueue::IsFull(PlayerQueue* queue)
{
	return (queue->size == queue->capacity);
}
int PlayerQueue::IsEmpty(PlayerQueue* queue)
{
	return (queue->size == 0);
}
void PlayerQueue::FrontInfo()
{
	cout << "\nFRONT ||\tPlayer: " << set[front]->m_name;
}
void PlayerQueue::BackInfo()
{
	cout << "\nBACK ||\tPlayer: " << set[back]->m_name;
}
Player* PlayerQueue::Front(PlayerQueue* q)
{
	if (IsEmpty(q))
	{
		cout << "\nThe queue is empty, no front item present.\n";
		return NULL;
	}
	return q->set[q->front];
}
Player* PlayerQueue::Back(PlayerQueue* q)
{
	if (IsEmpty(q))
	{
		cout << "\nThe queue is empty, no back item present.\n";
		return NULL;
	}
	return q->set[q->back];
}
void PlayerQueue::QueueInfo()
{
	cout << "\nQueue Info ||\tAmountInQueue: " << size << "\tQueue Capacity: " << capacity;
}
void PlayerQueue::PrintQueue()
{
	cout << "\nQueue Contents";
	for (int i = 0; i < set.size(); i++)
	{
		if (set[i] != NULL)
		{
			cout << "\nPlayer: " << set[i]->m_name << "\tQueue Position: " << i << " / " << size;
		}
	}
}