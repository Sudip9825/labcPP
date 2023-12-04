//parameterized constructor with single inheritance 
#include<iostream>

using namespace std; 
class A//creating a main class named A
{
	int a;				//privat data
	public:				//public data
		A(int x)
		{
			a=x;
		}
		void showa()
		{ 
		cout<<"value of A: "<<a<<endl;
		}
};
class B:public A // A ko info B ko public ma aayo

{
	int b;
	
	public:
		B(int x,int y):A(x)//x and y B ko info hoo.x chai A ma store hunxa
		
		{
			b=y;
		}
		void showall()
		{
			showa();
			cout<<"value ofB:"<<b<<endl;
				
		}
	};
	int main()
	{
		B obj1(2,9);
		obj1.showall();
	}
