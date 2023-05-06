#include <iostream>
#include<fstream>
#include <limits>
#include <string.h>
#include <unistd.h>
#include <windows.h> //for system cls and sleep and goto back: functions. 
#include <conio.h>   // for get function
using namespace std;

//CONCEPT OF POLYMORPHISM
//RUN TIME POLYMORPHISM.
//In this program their are two class pay_electric_bill (base class) & pay_gas_bill 
//(Drived class), in base class their is a funtion void print () this fuction is also
//in drived class with different work in calling process compiler confused to display 
//which  print() function so to resolve this problem we used virtual keyword with that
//funtion then its become virtual function

//========= Start of pay_electric_bill class ==============
class pay_electric_bill{
public:
	
    virtual void print (){ 					//concept of virtual function
	cout<< "\n\t\t\t\tThank you! Your Electric Bill is payed...!!" <<endl;
	}
	
    void getdata(){
    	
	string billnum;
	int billamount;
	int payamount; 

	cout << "\n\t\t\t\t\t-------------------------------"<< endl;
	cout << "\t\t\t\t\t\t>> BILL PAYMENT <<" << endl;
	cout << "\t\t\t\t\t-------------------------------" << endl;
	cout<<endl;
	cout<< "\t\t\t\tEnter your bill number of your Electric Bill : ";
	cin>>billnum;
	cout<<endl;
	cout<< "\t\t\t\tEnter your bill amount to bill : ";
	cin>>billamount;
	cout<<endl;
	cout<< "\t\t\t\tEnter your paymnet amount : ";
	cin>>payamount;

	if(billamount<payamount){
		int total = payamount - billamount;
		cout<<"\n\t\t\t\tTake Your Remaning Amount : "<<total;
	}

	if(billamount>payamount){
		int total = billamount - payamount;

		if(total<0){
			total = -(total);
			}

		cout<<"\n\t\t\t\tYou entre less amount  :"<<total<<endl;
		cout<<"please Pay More : "<<endl;
		cin>>payamount;

	}	
	}

};
//========= End of pay_electric_bill class ==============
   
//========= Start of pay_gas_bill class =============  
class pay_gas_bill:public pay_electric_bill{
	
public:
    void print (){ //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
    
	cout<< "\n\t\t\t\tThank you! Your Gas Bill is Payed...." <<endl;
//    this->getdata();	//using this keyword

	}
    void getdata(){
    	
	int billnum;
	int billamount;
	int payamount; 
	
	cout<< "\t\t\t\tEnter your bill number of your Gas Bill : ";
	cin>>billnum;
    cout<<endl;
	cout<< "\t\t\t\tEnter your bill amount to bill : ";
	cin>>billamount;
	cout<<endl;
	cout<< "\t\t\t\tEnter your paymnet amount : ";
	cin>>payamount;
	cout<<endl;
	
	if(billamount<payamount){
		int total = payamount - billamount;
		cout<<"\n\t\t\t\tTake Your Remaning Amount : "<<total;
	}
	
	if(billamount>payamount){
		int total = billamount - payamount;
		if(total<0){
			total = -(total);}
		cout<<"\n\t\t\t\tPay :"<<total<<"More : ";
		cin>>payamount;
	}	
	
	}	
int menu() {	
    pay_electric_bill *bptr;
    pay_gas_bill d;
    bptr = &d;
    // Non-virtual function, binded at compile time
    bptr->getdata(); 
    
    //virtual function, binded at runtime (Runtime polymorphism)
    bptr->print(); 
} 	
};
//========= End of pay_gas_bill class =============  
