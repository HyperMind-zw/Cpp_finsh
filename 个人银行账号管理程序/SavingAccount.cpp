#include<iostream>
#include<cmath>
using namespace std;

class SavingAccount {         //存户账户
private:
	int id;
	double balance;           //余额
	double rate;	         //年利率
	int lastDate;            //上次变更余额日期
	double accumulation;     //余额按日累计之和

	//记账，data日期，amount金额
	void record(int date, double amount);

	//获得的存款按日累加
	double accumulate(int date)const {
		return accumulation + balance * (date - lastDate);
	}

public:
	SavingAccount(int date, int id, double rate);
	int get_id() { return id; }
	double get_blance() { return balance; }
	double get_rate() { return rate; }
	void deposit(int date, double amount);  //存钱
	void withdraw(int date, double amount); //取钱
	void settle(int date); //结算利息，每年1月1号调用这个函数
	void show();   //显示账户信息
};

SavingAccount::SavingAccount(int date, int id, double rate) :id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
   cout << date << "\t#" << id << " is created" << endl;
}

void SavingAccount::record(int date, double amount) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;       //存取钱要向下取整，有什么用这个？
	balance += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}

void SavingAccount::deposit(int date,double amount){
	record(date, amount);
}

void SavingAccount::withdraw(int date, double amount) {
	if (amount > get_blance()) {
		cout << "Error:not enough money"<< endl;
	}
	else {
		record(date, -amount);
	}
}

void SavingAccount::settle(int date) {           
	double interest = accumulate(date) * rate / 365;      //计算年息
	if (interest != 0)                                    //严谨，排除余额是0的
		record(date,interest);
	accumulation = 0;									  //
}

void SavingAccount::show() {
	cout << "#" << id << "\tBalence:" << balance << endl;
}

int main() {
	SavingAccount sa0(1, 21325302, 0.015);
	SavingAccount sa1(1, 58320212, 0.015);

	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);

	sa0.settle(90);
	sa1.settle(90);

	sa0.show();
	sa1.show();
	return 0;
}