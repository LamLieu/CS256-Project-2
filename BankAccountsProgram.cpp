#include "stdafx.h"
#include "BankAccounts.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	double initialDeposit, annualInterestRate;

	//Sets up savings account
	cout << "How much money would you like to put into your savings account? (Initial deposit)" << endl << "-->";
	cin >> initialDeposit;
	cout << "What is the annual interest rate for your savings account?" << endl;
	cin >> annualInterestRate;
	SavingsAccount savings(initialDeposit, annualInterestRate);

	//Sets up checking account
	cout << "How much money would you like to put into your checking account? (Initial deposit)" << endl << "-->";
	cin >> initialDeposit;
	cout << "What is the annual interest rate for your savings account?" << endl << "-->";
	cin >> annualInterestRate;
	CheckingAccount checking(initialDeposit, annualInterestRate);

	double depositAmount, withdrawAmount;

	//Deposit and withdraw for savings account
	cout << "Please enter the amount that you want to deposit to your savings account" << endl << "-->";
	cin >> depositAmount;
	savings.deposit(depositAmount);
	cout << "Please enter the amount that you want to withdraw from your savings account" << endl << "-->";
	cin >> withdrawAmount;
	savings.withdraw(withdrawAmount);

	//Deposit and withdraw for checking account
	cout << "Please enter the amount that you want to deposit to your savings account" << endl << "-->";
	cin >> depositAmount;
	checking.deposit(depositAmount);
	cout << "Please enter the amount that you want to withdraw from your savings account" << endl << "-->";
	cin >> withdrawAmount;
	checking.withdraw(withdrawAmount);

	return 0;
}