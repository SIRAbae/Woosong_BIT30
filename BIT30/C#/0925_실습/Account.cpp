// Account.cpp

#include "std.h"


Account::Account()		{}


Account::Account( int id, String name, int balance)
{
	m_id		= id;
	m_balance	= balance;
	m_name		= name;

}


Account::Account( const Account & acc)
{
	m_id		= acc.m_id;
	m_balance	= acc.m_balance;
	m_name		= acc.m_name;
}


Account::~Account()
{
}


int Account::GetID()	  const	    
{ 
	return m_id; 
}


int Account::GetBalance() const	
{ 
	return m_balance; 
}


//-------- ���� �Լ��� ���� -------------------------
void Account::AddMoney(int val)
{
	if( val < 0 )		// ���̳ʽ� �ݾ׿� ���� ���� �߻�
		throw MinException(val);

	m_balance += val;
}
//---------------------------------------------------


void Account::MinMoney(int val)
{
	if( val < 0 )		// ���̳ʽ� �ݾ׿� ���� ���� �߻�
		throw MinException(val);

	if( m_balance < val )	// ���� ��� �䱸�� ���� ���� �߻�
		throw InsuffException(m_balance, val);

	m_balance -= val;
}


String Account::GetName() const
{
	return m_name;
}


//-------- ���� �Լ��� ���� -------------------------
void Account::ShowAllData() const
{
	cout << "����  ID : " << m_id << endl; 
	cout << "��    �� : " << m_name << endl;
	cout << "��    �� : " << m_balance << endl; 
}
//---------------------------------------------------