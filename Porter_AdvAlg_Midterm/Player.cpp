#include "Player.h"

Player::Player()
{
	m_name = "";
	m_TimeAfk = 0;
}
Player::Player(string name)
{
	m_name = name;
	m_TimeAfk = 0;
}
string Player::GetAccountName() 
{
	return accountName;
}
void Player::SetAccountName(string accName)
{
	accountName = accName;
}
int Player::GetAccountID()
{
	return accountID;
}
void Player::SetAccountID(int id)
{
	accountID = id;
}
void Player::SetAfkTimer(float maxTimeAfk) 
{
	m_MaxTimeAfk = maxTimeAfk;
}
void Player::SetActiveTimer(float timeToStayActive)
{
	m_activeTimer = timeToStayActive;
}
bool Player::IsAfk()
{
	return (m_TimeAfk >= m_MaxTimeAfk);
}
