/*
1 Solve this.
Fresh business scenario to apply inheritance , polymorphism   to emp based organization scenario.
Create Emp based organization structure --- Emp , Mgr , Worker
1.1 Emp state--- id(int), name, deptId , basicSalary(double)
Accept all of above in constructor arguments.
Methods ---
1.2. compute net salary ---ret 0
(eg : public double computeNetSalary(){return 0;})

1.2 Mgr state  ---id,name,basic,deptId , perfBonus
Add suitable constructor
Methods ----
1. compute net salary (formula: basic+perfBonus) -- override computeNetSalary

1.3 Worker state  --id,name,basic,deptId,hoursWorked,hourlyRate
Methods : 
1.  compute net salary (formula:  = basic+(hoursWorked*hourlyRate) --override computeNetSalary
2. get hrlyRate of the worker  -- add a new method to return hourly rate of a worker.(getter)

Create suitable array to store organization details.
Provide following options
1. Hire Manager
I/P : all manager details
2. Hire Worker  
I/P : all worker details
3. Display information of all employees net salary (by invoking computeNetSal), 
4. Exit
*/

#include<iostream>
#include<string.h>
using namespace std;

class Employee{
	private:
		int empID;
		int deptID;
		string empName;
	protected:
		double basicSalary;
		
	public:
		Employee(){
			
		}
		
		Employee(int empID, int deptID,string empName,double basicSalary){
			this->empID = empID;
			this->deptID = deptID;
			this->empName = empName;
			this->basicSalary = basicSalary;
		}
		
		void Display(){
			cout<<"Employee ID : "<<empID<<"\n"<<"Department ID : "<<deptID<<"\n"<<"Employee Name : "<<empName<<"\n"<<"Basic Salary : "<<basicSalary<<endl;
		}
		
		virtual void CalNetSalary(){
			cout<<"Net salary of Employee is : "<<basicSalary<<endl;
		}
		
};

class Manager:public Employee{
	private:
		double perfBonus;
		
	public:
		Manager(){
			
		}
		
		Manager(int empID, int deptID, string empName, double basicSalary, double perfBonus):Employee( empID,  deptID, empName, basicSalary){
			this->perfBonus = perfBonus;
		}
		
		
		void Display(){
			Employee::Display();
			cout<<"Performance Bonus : "<<perfBonus<<endl;
		}
		
		void CalNetSalary(){
			cout<<"Net Salary of Manager is : "<<perfBonus+this->basicSalary<<endl;
		}
		
};

class Worker:public Employee{
	private:
		int hrsWorked;
		double hrRate;
		
	public:
		Worker(){
			
		}
		
		Worker(int empID, int deptID,string empName,double basicSalary,int hrsWorked,double hrRate):Employee(empID,deptID,empName,basicSalary){
			this->hrsWorked = hrsWorked;
			this->hrRate = hrRate;
		}
		
		void Display(){
			Employee::Display();
			cout<<"Hours Worked : "<<hrsWorked<<"\n"<<"Hourly Rate : "<<hrRate<<endl;
		}
		
		void CalNetSalary(){
			cout<<"Net Salary of Worker is : "<<this->basicSalary+(hrsWorked*hrRate)<<endl;
		}
};
int main(){
	int empID, deptID;
	string empName;
	double basicSalary;
	double perfBonus;
	int hrsWorked;
	double hrRate;
	cout<<"Enter Employee ID and Department ID : ";
	cin>>empID>>deptID;
	cout<<"Enter Employee Name : ";
	cin>>empName;
	cout<<"Basic Salary of Employee : ";
	cin>>basicSalary;
	Employee emp(empID,deptID,empName,basicSalary);
	emp.Display();
	emp.CalNetSalary();
	
	cout<<"\n-----Manager----\n";
	
	cout<<"Enter Performance Bonus for Manager : ";
	cin>>perfBonus;
	Manager mgr(empID,deptID,empName,basicSalary,perfBonus);
	mgr.Display();
	mgr.CalNetSalary();
	
	cout<<"\n-----Worker------\n";
	cout<<"Enter Hours Worked : ";
	cin>>hrsWorked;
	cout<<"Enter Hourly Rate : ";
	cin>>hrRate;
	Worker worker(empID, deptID,empName,basicSalary,hrsWorked,hrRate);
	worker.Display();
	worker.CalNetSalary();
	
	return 0;
}
