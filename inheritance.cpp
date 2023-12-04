#include<iostream>
  using namespace std;
   class Employee // class super class
   {
   	private:
   		int id;
   		string name;
   		string address;
   		string phone;
   		string email;
   	public:
   		 Employee( int i, string n,string a,string p,string e) //constructor value  intialize 
   		 {
   		 	id=i;
   		 	name=n;
   		 	address= a;
   		 	phone=p;
   		 	email=e;
			}
	      void showEmp()
	      {
	      	cout<<"ID="<<id<<"\tName="<<name<<"\tAddress="<<address<<"\t phone"<<phone<<"email="<<email;
		  }
   };
   
   class programmer: public Employee //subclass 
   {
   	private: string prolang;
   	public:
   		programmer(int i,string n,string a,string p,string e,string prog):Employee(i,n,a,p,e)
   		{
   			prolang = prog;
		   }
		   
		   void displayInfo()
		   {
		   	showEmp();
		   	cout<<"programming langauge: "<<prolang<<endl;
		   }
   };
   
   
   int main()
   {
   	programmer p(1,"sudip","ktm","9839489384","sudip@ezxapmle.com","cpp");
   	p.displayInfo();
   	
   	return 0;

   }
   
   
   
   
   
  
