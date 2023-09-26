
#ifndef GAMESERVER_H
#define GAMESERVER_H
#include <iostream>
#include "PlayerQueue.h";
#include <iterator>
#include <vector>

using namespace std;

class GameServer
{

private:
	string serverName;
	int maxCapacity;
	int curCapacity;
	bool serverFull;

public:
	//main container
	vector<Player*> playerList;

	//basic sets/gets
	void SetMaxCapacity(int set);
	int GetMaxCapacity();
	void SetCurCapacity(int set);
	int GetCurCapacity();

	int RandomRange(int _low, int _high);
	//core func
	bool IsServerFull();
	bool IsServerEmpty();
	void AddPlayerToServer(Player* player);
	Player* RemovePlayer(int i);
	void AfkCheck(PlayerQueue* pq);
	void RandomDisconnect(PlayerQueue* pq, int i);
};
#endif