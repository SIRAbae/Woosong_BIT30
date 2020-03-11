// ContriAccount.h


#ifndef _CONTRIACCOUNT_H_
#define _CONTRIACCOUNT_H_

//------------------------------------------------------
// ContriAccount Class
// - 기부 계좌 
// - Account Class 상속 

// - 입금시 1%의 이자가 기부금으로 빠져 나간다.
//   상위 클래스의 AddMoney 함수 재정의 
// - 기부금 총액 저장 변수 필요 
//   int contribution
// - 출력시 총 기부액도 출력
//------------------------------------------------------

class ContriAccount : public Account
{
	int contribution;

public:
	ContriAccount(int id, String name, int balance );
	
	virtual void AddMoney(int val );

	virtual void ShowAllData();
};

#endif