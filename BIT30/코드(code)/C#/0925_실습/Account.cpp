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


//-------- 가상 함수로 수정 -------------------------
void Account::AddMoney(int val)
{
	if( val < 0 )		// 마이너스 금액에 대한 예외 발생
		throw MinException(val);

	m_balance += val;
}
//---------------------------------------------------


void Account::MinMoney(int val)
{
	if( val < 0 )		// 마이너스 금액에 대한 예외 발생
		throw MinException(val);

	if( m_balance < val )	// 과잉 출금 요구에 대한 예외 발생
		throw InsuffException(m_balance, val);

	m_balance -= val;
}


String Account::GetName() const
{
	return m_name;
}


//-------- 가상 함수로 수정 -------------------------
void Account::ShowAllData() const
{
	cout << "계좌  ID : " << m_id << endl; 
	cout << "이    름 : " << m_name << endl;
	cout << "잔    액 : " << m_balance << endl; 
}
//---------------------------------------------------