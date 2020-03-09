// Banka.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

int main()
{
    Bank *banka = new Bank(3, 5);
    Client* jarek = banka->CreateClient(2, "Jarek");
    Client* Roman = banka->CreateClient(7, "Roman");
    Client* Olin = banka->CreateClient(12, "Olin");

    Account* prvni = banka->CreateAccount(1, jarek, Roman);
    Account* druhy = banka->CreateAccount(2, Olin, 0.21);

    prvni->Deposit(70.4);
    druhy->Deposit(1202.4);
    druhy->AddInterest();
    banka->~Bank();
}

