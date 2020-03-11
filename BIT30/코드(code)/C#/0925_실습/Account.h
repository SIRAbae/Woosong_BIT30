// Account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_


class Account
{
	int		m_id;					// 계좌번호
	int		m_balance;				// 잔    액
	String	m_name;					

public:
	Account();	
	Account( int id, String name, int balance);

	Account( const Account & acc);
	~Account();

	int GetID()	  const;	    
	int GetBalance() const;	

	//-------- 가상 함수로 수정 -------------------------
	virtual void AddMoney(int val);
	//---------------------------------------------------

	void MinMoney(int val);
	String GetName() const;

	//-------- 가상 함수로 수정 -------------------------
	virtual void ShowAllData() const;

	//---------------------------------------------------

};


#endif