
#ifndef PLAYERQUEUE_H
#define PLAYERQUEUE_H
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;
class PlayerQueue
{

public:
	//member vars
	int front, back, size;	//we would convert these to our custom objects for manaing the different queue types that we want to implement
	int capacity;
	vector<Player*> set;	//a base container of objects for the queue to cache to
		//vector is also a good swap as we may have players that either disconnect while in a long wait and need to be allowed back into their queue position
		//brute forceable when required.
		//the vector was also needed to allot a large memory space.  Memory errors within heap as heap was being overloaded

	//member funcs
	//constructor
	PlayerQueue* constructQueue(int capacity);

	//Checks
	int IsFull(PlayerQueue* queue);
	int IsEmpty(PlayerQueue* queue);

	//Controls
	//add item into the queue, adjust the queue sizing for the new addition
	void Enqueue(PlayerQueue* q, Player* itemToAdd);
	//func type is the type of the item object we are removing, if it was player it would be Player Dequeue.
	Player* Dequeue(PlayerQueue* q);

	//Outputs
	void FrontInfo();
	void BackInfo();
	void QueueInfo();
	void PrintQueue();
	//Accesors
	//grabbing front item from the queue (also checks if empty)
	Player* Front(PlayerQueue* q);
	//grabbing back item from the queue (also checks if empty)
	Player* Back(PlayerQueue* q);

};
#endif