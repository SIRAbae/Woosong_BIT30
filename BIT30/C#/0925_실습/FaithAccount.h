// FaithAccount.h

#ifndef _FAITHACCOUNT_H_
#define _FAITHACCOUNT_H_

//------------------------------------------------------
// FaithAccount Class
// - 신용 계좌 
// - Account Class 상속 
// - 입금시 1%의 이자가 더해진다.
//   상위 클래스의 AddMoney 함수 재정의 
//------------------------------------------------------

class FaithAccount : public Account
{
public:
	FaithAccount(int id, String name, int balance );

	virtual void AddMoney( int val );

};




#endif
