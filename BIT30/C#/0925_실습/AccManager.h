// AccManager.h
#ifndef _ACCMANAGER_H_
#define _ACCMANAGER_H_



class AccManager
{
	Container<Account*> ctr;	// Account 저장을 위한 Container객체

public:
	AccManager();

	void PrintMenu();				// 메뉴 출력
	void MakeAccount();				// 계좌 개설을 위한 함수
	void Deposit();					// 입 금
	void Withdraw();				// 출 금
	void Inquire();					// 잔액 조회

	void fnEnter();

};

#endif