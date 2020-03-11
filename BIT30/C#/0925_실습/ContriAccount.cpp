// contriAccount.cpp

#include "std.h"

ContriAccount::ContriAccount(int id, String name, int balance )
: Account(id, name, balance-balance*0.01)
{
	contribution = balance * 0.01;
}


void ContriAccount::AddMoney(int val )
{
	Account::AddMoney( val - val*0.01);
	contribution += val*0.01;
}


void ContriAccount::ShowAllData()
{
	Account::ShowAllData();
	cout << "ÃÑ ±âºÎ¾× : " << contribution << endl;
	
}
