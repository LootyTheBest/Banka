#include "Account.h"

Account::Account(int n, Client* c)
{
	this->number = n;
	this->owner = c;
	this->partner = nullptr;
	this->balance = 0.0;
	this->interestRate = 0.0;
}

Account::Account(int n, Client* c, double ir)
{
	this->number = n;
	this->owner = c;
	this->partner = nullptr;
	this->balance = 0.0;
	this->interestRate = ir;
}

Account::Account(int n, Client* c, Client* p)
{
	this->number = n;
	this->owner = c;
	this->partner = p;
	this->balance = 0.0;
	this->interestRate = 0.0;
}

Account::Account(int n, Client* c, Client* p, double ir)
{
	this->number = n;
	this->owner = c;
	this->partner = p;
	this->balance = 0.0;
	this->interestRate = ir;
}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client* Account::GetOwner()
{
	return this->owner;
}

Client* Account::GetPartner()
{
	return this->partner;
}

bool Account::CanWithdraw(double a)
{
	if (this->balance >= a)
		return true;
	else return false;
	
}

void Account::Deposit(double a)
{
	this->balance += a;
}

void Account::Withdraw(double a)
{
	if (this->CanWithdraw(a))
		this->balance -= a;
}

void Account::AddInterest()
{
	this->balance += this->balance * this->interestRate;
}
