#include"head_atm.h"
#include<iostream>
using namespace std;

Card :: Card(int no,int p,Account* ac=0)
{
    number=no;
    pin=p;
    acc=ac;
}
/*Card :: Card(const Card &c)
{
	this->number=c.getnumber();
    pin=c.getpin();
    acc=c.getacc();
}*/
int Card :: getnumber()
{
	return number;
 }
 int Card :: getpin()
{
	return pin;
 }
Account* Card :: getacc()
{
	return acc;
 } 
bool Card :: validatePin(int p)
{
    return(p==pin);
}
bool Account :: makeDeposit(int amt)
{
	if(r_no<20)
	{
		rec[r_no].setrecord('d',r_no,amt);
    	r_no++;
	}
    balance+=amt;
    return true;
}
bool Account :: makeWithdrawal(int amt)
{
	if(r_no<20)
	{
		rec[r_no].setrecord('w',r_no,amt);
    	r_no++;
	}
    if(balance<amt)
    {
        return false;
    }
    else
    {
        balance=balance-amt;
        return true;
    }
}
/*void Account :: set_card(Card cd)
{
    card=cd;
}*/
/*Account ::Account(int no,int bal,Card cd)
{
    number=no;
    balance=bal;
    card=cd;
    
}*/
Account :: Account(int no,int bal)
{
    number=no;
    balance=bal;
    r_no=0;
}
/*Account :: Account(const Account &ac)
{
    number=ac.getnumber();
    balance=ac.getbalance();
    //card=ac.getcard()
}*/
int Account :: getnumber()
{
	return number;
}
int Account :: getbalance()
{
	return balance;
}
/*Card Account :: getcard()
{
	return card;
}*/
void Account :: printrec()
{
	int i;
	for(i=0;i<r_no;i++)
	{
		cout<<"Number : "<<rec[i].number<<endl;
		cout<<"Deposit(d)/Withdraw(w) : "<<rec[i].r<<endl;
		cout<<"Amount : "<<rec[i].amount<<endl;
		cout<<"Time : "<<rec[i].timeStamp<<endl<<endl;
	}
}
bool ATM :: deposite(Card cd,int p,int amt)
{
    startTransaction();
    bool b;
    if(cd.validatePin(p))
    {
        b=cd.acc->makeDeposit(amt);
    }
    else
    {
        b=false;
    }
    endTransaction();
    return b;
}
bool ATM :: withdraw(Card cd,int p,int amt)
{
    startTransaction();
    bool b;
    if(cd.validatePin(p))
    {
        b=cd.acc->makeWithdrawal(amt);
    }
    else
    {
        b=false;
    }
    endTransaction();
    
    return b;
}
void ATM :: startTransaction()
{
    t.num_running++;
}
void ATM :: endTransaction()
{
    t.num_running--;
    t.num_complete++;
}
Transaction :: Transaction()
{
	num_running=0;
	num_complete=0;
}
Record :: Record()
{
	number=0;
	amount=0;
	r='n';
	time_t timeStamp=time(0);
}
void Record ::  setrecord(char ch,int no,int amt)
{
	r=ch;
	number=no;
	amount=amt;	
}
