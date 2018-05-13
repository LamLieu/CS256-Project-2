#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class BankAccount {
private:
	double balance;
	double numberOfDepositsThisMonth;
	double numberOfWithdrawals;
	double annualInterestRate;
	double monthlyServiceCharge;
protected:
	BankAccount(double balance, double annualInterestRate);
public:
	virtual void deposit(double depositAmount);
	virtual void withdraw(double withdrawAmount);
	virtual void calcInt();
	virtual void monthlyProc();

	double getNumberOfWithdrawals();
	double getBalance();

	void setMonthlyServiceCharge(double newMonthlyServiceCharge);
	void setBalance(double newBalance);
};

class SavingsAccount : public BankAccount {
private:
	bool status;
public:
	SavingsAccount(double balance, double annualInterestRate);
	void setInitialStatus();
	void withdraw(double withdrawAmount);
	void deposit(double depositAmount);
	void monthlyProc();
};

class CheckingAccount : public BankAccount {
public:
	CheckingAccount(double balance, double annualInterestRate);
	void withdraw(double withdrawAmount);
	void monthlyProc();
};