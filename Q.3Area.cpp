/*
3:Create a abstract class Shape with pure virtual method area;
Create Rectangle,Circle,Square class..inherit them from Shape class..Override area method.
Test these all classes by creating object of respective class.
*/


#include<iostream>
using namespace std;

class Shape{
	public :
		virtual float area() = 0; //pure virtual function //we can't create object of abstract class.also no need of constructor
		virtual void Accept() = 0;
};

class Rectangle:public Shape{
	private:
		float length, breadth;
	public:
		void Accept(){
			cout<<"Enter Length : ";
			cin>>length;
			cout<<"Enter Breadth : ";
			cin>>breadth;
		}
		float area(){
			cout<<"Area of Rectangle : "<<length * breadth<<endl;
		}
};
class Circle:public Shape{
	private:
		float radius;
	public:
		void Accept(){
			cout<<"Enter radius : ";
			cin>>radius;
		}
		
		float area(){
			cout<<"area of circle = "<<(3.142 * radius * radius)<<endl; 
		}
};
class Square:public Shape{
	private:
		float length;
	public:
		void Accept(){
			cout<<"Enter Length : ";
			cin>>length;
		}
		
		float area(){
		cout<<"Area of Square : "<<(length * length );	
		}
		
};
int main()
{	
	Rectangle rectangle;
	rectangle.Accept();
	rectangle.area();
	cout<<"\n--------------\n";
	
	Circle circle;
	circle.Accept();
	circle.area();
	cout<<"\n--------------\n";
	Square square;
	square.Accept();
	square.area();
	cout<<"\n--------------\n";
	
	return 0;
}
