// FaithAccount.h

#ifndef _FAITHACCOUNT_H_
#define _FAITHACCOUNT_H_

//------------------------------------------------------
// FaithAccount Class
// - �ſ� ���� 
// - Account Class ��� 
// - �Աݽ� 1%�� ���ڰ� ��������.
//   ���� Ŭ������ AddMoney �Լ� ������ 
//------------------------------------------------------

class FaithAccount : public Account
{
public:
	FaithAccount(int id, String name, int balance );

	virtual void AddMoney( int val );

};




#endif
