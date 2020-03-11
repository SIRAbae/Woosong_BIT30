// AccManager.cpp


#include "std.h"

AccManager::AccManager()
{
}


// �޴� ���
void AccManager::PrintMenu()				
{
	cout << "---------------- MENU  --------------\n";
	cout << "1. ���� ����" << endl; 
	cout << "2. �� ��"     << endl;
	cout << "3. �� ��"	   << endl;
	cout << "4. �ܾ���ȸ"  << endl;
	cout << "5. ���α׷� ����" << endl; 
	cout << "-------------------------------------\n\n";

}




/************************************************************************

 �� �� �� : AccManager::MakeAccount()
 ��    �� : ���� ���� �Լ�
 ��    �� : void
 �� �� �� : void
 �󼼼��� : ����ڷκ��� ���� �輳 ������ �Է¹ް� 
            �Է� ����� ���� ���¸� ����
			(�Ϲ� ����, �ſ� ����, ��� ����)
		    ������ ���¸� �ɹ� ������ ����
			Account* pArray[index];

************************************************************************/
void AccManager::MakeAccount()				
{
	int		id;
	char	name[NAME_LEN];
	int		balance;
	int     sel;


	cout << "������ ������ ���� -----------------" << endl;
	cout << " 1. �Ϲ� ����. " << endl;
	cout << " 2. �ſ� ����. " << endl;
	cout << " 3. ��� ����. " << endl;
	cout << " >> ";
	cin  >> sel;

	cout << "���� ���� -----------------" << endl;
	cout << "�� �� ID : ";		cin >> id;
	cout << "��    �� : ";		cin >> name;
	cout << "�� �� �� : ";		cin >> balance;

	if( sel == 1 )
		ctr.Insert( new Account(id, name, balance));
	else if( sel == 2 )
		ctr.Insert( new FaithAccount(id, name, balance));

	else if( sel == 3 )
		ctr.Insert( new ContriAccount(id, name, balance));

	else
		cout << "���� ����" << endl; 

	fnEnter();
}


// �� ��
void AccManager::Deposit()					
{
	int		money;
	int		id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;


	int num = ctr.GetElemSum();		// ���� �� ���� ����

	try
	{
		for( int i=0; i < num; i++)
		{
			if( ctr.GetItem(i)->GetID() == id )
			{
				ctr.GetItem(i)->AddMoney(money);
				cout << "�Ա� �Ϸ�" << endl;
				fnEnter();
				return;
			}
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl; 
	}
	catch( MinException & ex )
	{
		ex.What();
	}
	fnEnter();
}


void AccManager::Withdraw()				// �� ��
{
	int	money;
	int	id;

	cout << "�� �� ID : ";		cin >> id;
	cout << "�� �� �� : ";		cin >> money;

	int num = ctr.GetElemSum();		// ���� �� ���� ����


	try
	{
		for( int i=0; i < num; i++)
		{
			if( ctr.GetItem(i)->GetID() == id )
			{
				if( ctr.GetItem(i)->GetBalance() < money)
				{
					cout << "�ܾ� ���� " << endl;
					fnEnter();
					return;
				}
				ctr.GetItem(i)->MinMoney(money);
				cout << "��� �Ϸ�" << endl;
				fnEnter();
				return;
			}
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl; 
	}
	catch( MinException & ex )
	{
		ex.What();
	}
	catch( InsuffException & ex )
	{
		ex.What();
	}

	fnEnter();
}

void AccManager::Inquire()					// �ܾ� ��ȸ
{
	int num = ctr.GetElemSum();		// ���� �� ���� ����
	for( int i=0; i < num; i++)
	{
		ctr.GetItem(i)->ShowAllData();
	}
	fnEnter();
}

void AccManager::fnEnter()
{
	int temp = 0;
	printf("Press Any Key\n");
	getche();
}