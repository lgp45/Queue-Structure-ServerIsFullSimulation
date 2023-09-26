
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Define.h"

using namespace std;
enum Status {active, afk, offline};
class Player
{
private:
	string accountName;
	int accountID;
public:
	//id
	string m_name;
	int m_Id;
	int m_Level;

	//activity status
	float m_activeTimer;

	Status m_Status;
	bool m_Afk;
	float m_TimeAfk;
	float m_MaxTimeAfk;

	//setup funcs
	Player();
	Player(string name);

	//account cache
	string GetAccountName();
	void SetAccountName(string accName);
	int GetAccountID();
	void SetAccountID(int id);

	//activity status control func
	void SetActiveTimer(float timeToStayActive);
	void SetAfkTimer(float maxTimeAfk);
	bool IsAfk();
	void SendOffline();
	void SendOffline(Player p, float timeLimit);

};
#endif