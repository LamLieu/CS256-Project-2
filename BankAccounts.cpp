#include "stdafx.h"
#include "BankAccounts.h"
#include <string>
#include <iostream>
using namespace std;

BankAccount::BankAccount(double balance, double annualInterestRate) {
	this->balance = balance;
	this->annualInterestRate = annualInterestRate;
}

void BankAccount::deposit(double depositAmount) {
	balance += depositAmount;
	numberOfDepositsThisMonth++;
	cout << "Your balance is now: " << getBalance() << endl;
}

void BankAccount::withdraw(double withdrawAmount) {
	balance -= withdrawAmount;
	numberOfWithdrawals++;
	cout << "Your balance is now: " << getBalance() << endl;
}

void BankAccount::calcInt() {
	double monthlyInterestRate = annualInterestRate / 12;
	double monthlyInterest = balance * monthlyInterestRate;
	balance += monthlyInterest;
}

void BankAccount::monthlyProc() {
	balance -= monthlyServiceCharge;
	calcInt();
	numberOfWithdrawals = 0;
	numberOfDepositsThisMonth = 0;
	monthlyServiceCharge = 0;
}

double BankAccount::getNumberOfWithdrawals() {
	return numberOfWithdrawals;
}

double BankAccount::getBalance() {
	return balance;
}

void BankAccount::setMonthlyServiceCharge(double newMonthlyServiceCharge) {
	monthlyServiceCharge = newMonthlyServiceCharge;
}

void BankAccount::setBalance(double newBalance) {
	balance = newBalance;
}

SavingsAccount::SavingsAccount(double balance, double annualInterestRate) : BankAccount(balance, annualInterestRate) {
	cout << "Savings account created." << endl << endl;
	setInitialStatus();
}

void SavingsAccount::setInitialStatus() {
	if (getBalance() >= 25) {
		status = true;
	}
}

void SavingsAccount::withdraw(double withdrawAmount) {
	if (!status) {
		cout << "Your account is not active, so the withdrawal cannot be made." << endl;
	}
	else {
		BankAccount::withdraw(withdrawAmount);
	}
}
void SavingsAccount::deposit(double depositAmount) {
	if (!status) {
		cout << "Your account is currently inactive." << endl;
		cout << "If the balance of your account is above $25 after your deposit, your account will be set to active." << endl;
		BankAccount::deposit(depositAmount); 
		if (getBalance() >= 25) {
			status = true;
		}
	}
	else {
		BankAccount::deposit(depositAmount);
	}
}

void SavingsAccount::monthlyProc() {
	if (getNumberOfWithdrawals() > 4) {
		setMonthlyServiceCharge(1);
	}
	BankAccount::monthlyProc();
}

CheckingAccount::CheckingAccount(double balance, double annualInterestRate) : BankAccount(balance, annualInterestRate) {
	cout << "Checking account created!" << endl << endl;
}
void CheckingAccount::withdraw(double withdrawAmount) {
	if (getBalance() - withdrawAmount < 0) {
		cout << "Since your account balance went below $0, a service charge of $15 will be taken from your account.";
		setBalance(getBalance() - 15);
	}
	BankAccount::withdraw(withdrawAmount);
}
void CheckingAccount::monthlyProc() {
	setMonthlyServiceCharge(5 + (.1 * getNumberOfWithdrawals()));
	BankAccount::monthlyProc();
}