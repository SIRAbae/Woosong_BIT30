// ContriAccount.h


#ifndef _CONTRIACCOUNT_H_
#define _CONTRIACCOUNT_H_

//------------------------------------------------------
// ContriAccount Class
// - ��� ���� 
// - Account Class ��� 

// - �Աݽ� 1%�� ���ڰ� ��α����� ���� ������.
//   ���� Ŭ������ AddMoney �Լ� ������ 
// - ��α� �Ѿ� ���� ���� �ʿ� 
//   int contribution
// - ��½� �� ��ξ׵� ���
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