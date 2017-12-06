#include <iostream>
#include"all_methods.cpp"
using namespace std;

int main()
{
    int done,option,no,amt,p;
    done=0;
    cout<<"Enter your account no."<<endl;
    cin>>no;
    cout<<"Enter the amount in your account "<<endl;
    cin>>amt;
    Account acc(no,amt);
    cout<<"Enter your card no."<<endl;
    cin>>no;
    cout<<"Enter card's pin number"<<endl;
    cin>>p;
    Card atm_card(no,p,&acc);
    ATM atm;
    bool check;
    while(done==0)
    {
        cout<<endl<<"Enter option number"<<endl;
        cout<<"1)Withdraw "<<endl<<"2)Deposite"<<endl<<"3)Print transactions"<<endl;
		cout<<"4)Rcords"<<endl<<"5)end program"<<endl;
        cout<<"********************************"<<endl;
		cin>>option;
        switch(option)
        {
        case 1:
        	cout<<"Enter pin no. of your card"<<endl;
        	cin>>no;
        	cout<<"Enter amount to be withdrawn"<<endl;
        	cin>>amt;
        	check=atm.withdraw(atm_card,no,amt);
        	if(check==true)
        	{
        		cout<<"Successful transaction"<<endl;
			}
			else
			{
				cout<<"Unsuccessful transaction"<<endl;
			}
            break;
        case 2:
        	cout<<"Enter pin no. of your card"<<endl;
        	cin>>no;
        	cout<<"Enter amount to be deposited"<<endl;
        	cin>>amt;
        	check=atm.deposite(atm_card,no,amt);
        	if(check==true)
        	{
        		cout<<"Successful transaction"<<endl;
			}
			else
			{
				cout<<"Unsuccessful transaction"<<endl;
			}
            break;
        case 3:
        	cout<<"Running transactions : "<<atm.t.num_running<<endl;;
        	cout<<"Completed Transactions : "<<atm.t.num_complete<<endl;
        	
            break;
        case 4:
        	cout<<"Enter pin no. of your card"<<endl;
        	cin>>no;
        	if(atm_card.validatePin(no))
        	{
        		atm_card.acc->printrec();
			}
            else
            {
            	cout<<"Incorrect pin"<<endl;
			}
            break;
        case 5:
            done=1;
            break;
        default:
            cout<<"Not a valid entry.Please enter a valid number"<<endl;
        }
    }
    return 0;

}

