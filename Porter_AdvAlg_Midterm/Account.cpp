#include "Account.h"

Account::Account() 
{

}
Account::Account(int id)
{
	m_id = id;
}
Account::Account(string name)
{
	m_name = name;
}
Account::Account(int id, string name)
{
	m_id = id;
	m_name = name;
}
int Account::GetID() 
{
	return m_id;
}
void Account::SetID(int id)
{

}
string Account::GetAccountName()
{
	return m_name;
}
void Account::SetAccountName(string accName)
{
	
}