// AccManager.h
#ifndef _ACCMANAGER_H_
#define _ACCMANAGER_H_



class AccManager
{
	Container<Account*> ctr;	// Account ������ ���� Container��ü

public:
	AccManager();

	void PrintMenu();				// �޴� ���
	void MakeAccount();				// ���� ������ ���� �Լ�
	void Deposit();					// �� ��
	void Withdraw();				// �� ��
	void Inquire();					// �ܾ� ��ȸ

	void fnEnter();

};

#endif