#include<iostream>
using namespace std;
#include<string>
#include<ctime>
class Account;
class Transaction;
class Record
{
	public:
		int number;
		char r;
		int amount;
		long timeStamp;
		Record();
		void setrecord(char,int,int);
		
};
class Card
{
	int number;
	int pin;
	
public:
	Account *acc;
    Card(int,int,Account*);
    Card(int,int);
    //Card(const Card&);
    int getnumber();
    int getpin();
    Account * getacc();
    bool validatePin(int);
};
class Account
{
	int r_no;
	int number;
	int balance;
	//Card card;
	public:
		Record rec[20];
		void printrec();
		bool makeDeposit(int);
		bool makeWithdrawal(int);
		//void set_card(Card);
		int getnumber();
		int getbalance();
		//Card getcard();
		//Account(int,int,Card);
		Account(const Account&);
		Account(int,int);
};
class Transaction
{
	public:
		int num_running;
		int num_complete;
		Transaction();
};
class ATM
{
    
	public:
		Transaction t;
		bool deposite(Card,int,int);
		bool withdraw(Card,int,int);
		void startTransaction();
		void endTransaction();
	//	ATM();
	//	~ATM();
};


/*class Deposit
{

};
class Withdrawal
{

};
*/
