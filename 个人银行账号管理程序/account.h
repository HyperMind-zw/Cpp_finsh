class SavingAccount {         //存户账户
private:
	int id;
	double balance;           //余额
	double rate;	         //年利率
	int lastDate;            //上次变更余额日期
	double accumulation;     //余额按日累计之和
	static double total;     //所有账号总金额

	//记账，data日期，amount金额
	void record(int date, double amount);

	//获得的存款按日累加
	double accumulate(int date)const {
		return accumulation + balance * (date - lastDate);
	}

public:
	SavingAccount(int date, int id, double rate);
	int get_id()const { return id; }
	double get_blance() const{ return balance; }
	double get_rate() const{ return rate; }
	static double get_Total() { return total; }
	void deposit(int date, double amount);  //存钱
	void withdraw(int date, double amount); //取钱
	void settle(int date); //结算利息，每年1月1号调用这个函数
	void show();   //显示账户信息
};
