#include "GameServer.h";

void GameServer::SetMaxCapacity(int set)
{
	maxCapacity = set;
}
int GameServer::GetMaxCapacity()
{
	return maxCapacity;
}
void GameServer::SetCurCapacity(int set)
{
	curCapacity = set;
}
int GameServer::GetCurCapacity()
{
	return curCapacity;
}

//core func
bool GameServer::IsServerFull()
{
	return (curCapacity == maxCapacity);
}
bool GameServer::IsServerEmpty()
{
	return (curCapacity == 0);
}
void GameServer::AddPlayerToServer(Player* player)
{
	if (IsServerFull())
	{
		cout << "\nThis server is currently full.";
		return;
	}
	playerList.push_back(player);
	curCapacity = playerList.size();
	cout << "\nAdding Player: " << player->m_name << " to GameServer. Server Capacity: " << curCapacity << "/" << maxCapacity;
}
Player* GameServer::RemovePlayer(int i)
{
	return playerList[i];
}
void GameServer::AfkCheck(PlayerQueue* pq)
{
	for (int i = 0; i < playerList.size(); i++)
	{
		/*
		if (playerList[i]->m_activeTimer <= 0)
		{
			playerList[i]->m_Afk = true;
			//playerList[i]->m_Status = Status::afk;
		}
		if (playerList[i]->IsAfk() == true && playerList[i]->m_TimeAfk >= playerList[i]->m_MaxTimeAfk)
		{
			cout << "\nRemoving AFK Player from GameServer || Player: " << playerList[i]->m_name;
			playerList.erase(playerList.begin() + i);
		}
		*/
		if (playerList[i]->m_TimeAfk >= playerList[i]->m_MaxTimeAfk)
		{

			cout << "\nAFK TIMEOUT\tRemoving Player: " << playerList[i]->m_name <<" from GameServer ||  ";
			playerList.erase(playerList.begin() + i);
			curCapacity = playerList.size();
			cout << " Server Capacity : " << curCapacity << " / " << maxCapacity;

		}

	}
	
}
int GameServer::RandomRange(int _low, int _high)
{
	//srand(time(NULL));
	return rand() % ((_high - _low) + 1) + _low;
}
void GameServer::RandomDisconnect(PlayerQueue* pq, int i)
{

	for (int f = 0; f < i; f++)
	{
		if (playerList.size() >= i)
		{
			if (!IsServerEmpty())
			{
				cout << "\nDISCONNECTED\tPlayer: " << playerList[f]->m_name;
				playerList.erase(playerList.begin() + f);
				curCapacity = playerList.size();
				cout << " has disconnected...Removing from server." << " Server Capacity: " << curCapacity << " / " << maxCapacity;

			}
		}
		else
		{
			cout << "\nNo players online to disconnect.";
		}
	}
	playerList.shrink_to_fit();
}


