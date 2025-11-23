#include "account.h"
#include<iostream>
#include<cmath>
using namespace std;

double SavingAccount::total = 0; // 初始化静态成员变量

SavingAccount::SavingAccount(int date, int id, double rate) :id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	cout << date << "\t#" << id << " is created" << endl;
}

void SavingAccount::record(int date, double amount) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;       //存取钱要向下取整，有什么用这个？
	balance += amount;
	total += amount;//
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}

void SavingAccount::deposit(int date, double amount) {
	record(date, amount);
}

void SavingAccount::withdraw(int date, double amount) {
	if (amount > get_blance()) {
		cout << "Error:not enough money" << endl;
	}
	else {
		record(date, -amount);
	}
}

void SavingAccount::settle(int date) {
	double interest = accumulate(date) * rate / 365;      //计算年息
	if (interest != 0)                                    //严谨，排除余额是0的
		record(date, interest);
	accumulation = 0;									  //新起点
}

void SavingAccount::show() {
	cout << "#" << id << "\tBalence:" << balance << endl;
}