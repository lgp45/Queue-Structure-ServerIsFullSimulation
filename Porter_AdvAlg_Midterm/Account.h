
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "Player.h"
using namespace std;

class Account
{
private:
	int m_id;
	string m_name;

public:
	//ease of use and testing
	Player* character;

	//constructor
	Account();
	Account(int id);
	Account(string name);
	Account(int id, string name);
	//basics
	int GetID();
	void SetID(int id);
	string GetAccountName();
	void SetAccountName(string accName);

}; 
#endif