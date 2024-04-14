/*
2:Create cpp application for bank account handling.
2.1. Create a class BankAccount -- acct no(int),customer name(string),balance(double)
Add  constr. (2 constrs : first to accept all details )

2.2 Add Business logic methods
Methods
public void withdraw(double amt) 
public void deposit(double amt)

2.3: Create object of account class and test withdraw and deposit methods.
*/

#include<iostream>
using namespace std;
class BankAccount{
	private :
	 	int acctNo;
	 	string custName;
	 	double balance , withdraw, deposit;
	 	
	public :
		BankAccount(){
			

		}
		BankAccount(int acctNo, string custName, double balance ){
			this->acctNo=acctNo;
			this->custName=custName;
			this->balance=balance;
		}
		void Display(){
			cout<<"  Account No. : "<<acctNo<<"\n"<<" Customer Name : "<<custName<<"\n"<<" Account Balance : "<<balance<<endl;
			
		}
		void Withdraw(){
			cout<<" Amount Withdraw : " ;
			cin>>withdraw;
			if(withdraw<balance){
				balance= balance - withdraw;
				cout<<"  Current Balance  : "<<balance<<endl;
		
			}
			else{
				cout<<"  Insufficient Balance : ";
				cout<<"  Current Balance  : "<<balance<<endl;	
			}
	
		}
		void Deposit(){
				cout<<" Deposit Amount : ";
				cin>>deposit;
				balance = balance + deposit;
				cout<<" Current Balance : "<<balance<<endl;
		}
};

int main()
{
	int acctNo;
	string custName;
	double balance;
	cout<<" Account No. : ";
	cin>>acctNo;
	cout<<" Customer Name : ";
	cin>>custName;
	cout<<" Account Balance : ";
	cin>>balance;
	BankAccount bankAcct(acctNo, custName, balance);
	bankAcct.Display();
	bankAcct.Withdraw();
	bankAcct.Deposit();
	return 0;
}
