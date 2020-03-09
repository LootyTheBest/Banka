#include "Bank.h"

Bank::Bank(int c, int a)
{
	this->clients = new Client * [c];
	this->accounts = new Account * [a];
	this->clientsCount = 0;
	this->accountsCount = 0;
}

Bank::~Bank()
{
	for (int i = 0; i < this->clientsCount; i++) {
		delete this->clients[i];
	}
	for (int x = 0; x < this->accountsCount; x++) {
		delete this->accounts[x];
	}
	delete this->clients;
	delete this->accounts;
	this->accountsCount = 0;
	this->clientsCount = 0;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < this->clientsCount; i++) {
		if (c == this->clients[i]->GetCode())
			return this->clients[i];
	}
	return nullptr;
}

Account* Bank::GetAccount(int n)
{
	for (int i = 0; i < this->accountsCount; i++) {
		if (n == this->accounts[i]->GetNumber())
			return this->accounts[i];
	}
	return nullptr;
}

Client* Bank::CreateClient(int c, string n)
{
	this->clients[this->clientsCount] = new Client(c, n);
	this->clientsCount++;
	return clients[clientsCount - 1];
}

Account* Bank::CreateAccount(int n, Client* c)
{
	this->accounts[this->accountsCount] = new Account(n, c);
	this->accountsCount++;
	return this->accounts[this->accountsCount-1];
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	this->accounts[this->accountsCount] = new Account(n, c, ir);
	this->accountsCount++;
	return this->accounts[this->accountsCount - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p)
{
	this->accounts[this->accountsCount] = new Account(n, c, p);
	this->accountsCount++;
	return this->accounts[this->accountsCount - 1];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	this->accounts[this->accountsCount] = new Account(n, c, p, ir);
	this->accountsCount++;
	return this->accounts[this->accountsCount - 1];
}

void Bank::AddInterest()
{
	for (int i = 0; i < this->accountsCount; i++) {
		this->accounts[i]->AddInterest();
	}
}
