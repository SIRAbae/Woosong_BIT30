// FaithAccount.cpp

#include "std.h"

FaithAccount::FaithAccount(int id, String name, int balance )
: Account(id, name, balance+balance*0.01)
{}

void FaithAccount::AddMoney( int val )
{
	Account::AddMoney( val + val *0.01 );
}
