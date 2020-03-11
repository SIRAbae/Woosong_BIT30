// AccManager.cpp


#include "std.h"

AccManager::AccManager()
{
}


// 메뉴 출력
void AccManager::PrintMenu()				
{
	cout << "---------------- MENU  --------------\n";
	cout << "1. 계좌 개설" << endl; 
	cout << "2. 입 금"     << endl;
	cout << "3. 출 금"	   << endl;
	cout << "4. 잔액조회"  << endl;
	cout << "5. 프로그램 종료" << endl; 
	cout << "-------------------------------------\n\n";

}




/************************************************************************

 함 수 명 : AccManager::MakeAccount()
 기    능 : 계좌 개설 함수
 인    자 : void
 리 턴 값 : void
 상세설명 : 사용자로부터 계좌 계설 종류를 입력받고 
            입력 결과에 따른 계좌를 개설
			(일반 계좌, 신용 계좌, 기부 계좌)
		    개설된 계좌를 맴버 변수에 저장
			Account* pArray[index];

************************************************************************/
void AccManager::MakeAccount()				
{
	int		id;
	char	name[NAME_LEN];
	int		balance;
	int     sel;


	cout << "개설할 계좌의 종류 -----------------" << endl;
	cout << " 1. 일반 계좌. " << endl;
	cout << " 2. 신용 계좌. " << endl;
	cout << " 3. 기부 계좌. " << endl;
	cout << " >> ";
	cin  >> sel;

	cout << "계좌 개설 -----------------" << endl;
	cout << "계 좌 ID : ";		cin >> id;
	cout << "이    름 : ";		cin >> name;
	cout << "입 금 액 : ";		cin >> balance;

	if( sel == 1 )
		ctr.Insert( new Account(id, name, balance));
	else if( sel == 2 )
		ctr.Insert( new FaithAccount(id, name, balance));

	else if( sel == 3 )
		ctr.Insert( new ContriAccount(id, name, balance));

	else
		cout << "선택 오류" << endl; 

	fnEnter();
}


// 입 금
void AccManager::Deposit()					
{
	int		money;
	int		id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "입 금 액 : ";		cin >> money;


	int num = ctr.GetElemSum();		// 계좌 총 개수 리턴

	try
	{
		for( int i=0; i < num; i++)
		{
			if( ctr.GetItem(i)->GetID() == id )
			{
				ctr.GetItem(i)->AddMoney(money);
				cout << "입금 완료" << endl;
				fnEnter();
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다." << endl; 
	}
	catch( MinException & ex )
	{
		ex.What();
	}
	fnEnter();
}


void AccManager::Withdraw()				// 출 금
{
	int	money;
	int	id;

	cout << "계 좌 ID : ";		cin >> id;
	cout << "출 금 액 : ";		cin >> money;

	int num = ctr.GetElemSum();		// 계좌 총 개수 리턴


	try
	{
		for( int i=0; i < num; i++)
		{
			if( ctr.GetItem(i)->GetID() == id )
			{
				if( ctr.GetItem(i)->GetBalance() < money)
				{
					cout << "잔액 부족 " << endl;
					fnEnter();
					return;
				}
				ctr.GetItem(i)->MinMoney(money);
				cout << "출금 완료" << endl;
				fnEnter();
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다." << endl; 
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

void AccManager::Inquire()					// 잔액 조회
{
	int num = ctr.GetElemSum();		// 계좌 총 개수 리턴
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