// Account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_


class Account
{
	int		m_id;					// ���¹�ȣ
	int		m_balance;				// ��    ��
	String	m_name;					

public:
	Account();	
	Account( int id, String name, int balance);

	Account( const Account & acc);
	~Account();

	int GetID()	  const;	    
	int GetBalance() const;	

	//-------- ���� �Լ��� ���� -------------------------
	virtual void AddMoney(int val);
	//---------------------------------------------------

	void MinMoney(int val);
	String GetName() const;

	//-------- ���� �Լ��� ���� -------------------------
	virtual void ShowAllData() const;

	//---------------------------------------------------

};


#endif