#include <iostream>

using namespace std;
//CONCEPT OF NESTED CLASS:
//In this program their is a class Insurance which is a base class and other class called   
//Vehicle_Insurance which is the drived class of Insurance in this drived class their
//is another class Engine which is the nested of Vehicle_Insurance class.

//========== Start of Insurance class =========
class Insurance{
	public:
		string name;
		string dob;
		string address;
		string gender;
		int years;
		int age;
		int cinc;
		int sd; 
		int ed;
		void meun();
void Register(){
	cout << "\n\t\t\t\t\t-------------------------------"<<endl;
	cout << "\t\t\t\t\t>> APPLYING FORM <<" << endl;
	cout << "\t\t\t\t\t-------------------------------" <<endl;	
	cout<<"\t\t\t\tEnter your name : ";
	cin>>name;
	cout<<endl;
	cout<<"\t\t\t\tEnter your Address : ";
	cin>>address;
	cout<<endl;
	cout<<"\t\t\t\tEnter your gender : ";
	cin>>gender;
	cout<<endl;
	cout<<"\t\t\t\tEnter your Date of Birth : ";
	cin>>dob;
	cout<<endl;
	cout<<"\t\t\t\tEnter your age : ";
	cin>>age;
	cout<<endl;
	cout<<"\t\t\t\tEnter your CNIC : ";
	cin>>cinc;
	cout<<endl;	
	cout<<"\t\t\t\tEnter number of years : ";
	cin>>years;
	cout<<endl;	
	cout<<"\t\t\t\tEnter Date For When Policy To Be Effective: ";
	cin>>sd;
	cout<<endl;
	cout<<"\t\t\t\tEnter Date For When Policy To Be Expiry: ";
	cin>>ed;
	cout<<endl;			
}
void monthlyins(){
	int mon_ins = 5000/years;
	cout<<"\n\t\t\t\tYOUR MONTHLY INSTALMENT =  "<<mon_ins;
	cout<<endl;
}
};
//========== End of Insurance class =========

//=========== Start of Vehicle_Insurance class =====
class Vehicle_Insurance:public Insurance{
	public:	
	string Vehicle_num;
		int get_Vehicle_num(){
			cout<<"\n\t\t\t\tEnter your Vehicle number : ";
			cin>>Vehicle_num; 
			cout<<endl;
		}
//start of nested class declaration	
class Engine{
	public:
	string Enginecc;
		int get_Enginecc(){
			cout<<"\n\t\t\t\tCar Engine Specifications are : ";
			cin>>Enginecc;			
		}//declaration nested class ends here
		void inu(){
			cout<<"\n\t\t\t\tFor Vehicle Insurance your monthly instalment is 5000/= Rupees ";
			cout<<endl;
		}
};		
	Engine Enginecc;
};
//=========== End of Vehicle_Insurance =====

void Insurance::meun(){
	Insurance i;
	Vehicle_Insurance *obj1 = new Vehicle_Insurance(); //using new keyword 
	i.Register();
	obj1->get_Vehicle_num();
	obj1->Enginecc.get_Enginecc();
	obj1->Enginecc.inu();
	i.monthlyins();
	delete obj1;			//using delete keyword
}
