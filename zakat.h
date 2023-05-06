#include <iostream>
using namespace std;

//Concept of template function
		//placeholder
template <typename T > 				//using template keyword
T getpersonaldatadata(string x,T y){		//here arrguments are two in which on is constant string and other is T which will be any thing 
	cout<<x;
	cin>>y;
	return y;		//return the user enter data 
}

//Concept of template function
		//placeholder
template <typename X> 
X getfinancialdata(string x,X y){			//here arrguments are two in which on is constant string and other is T which will be any thing 
	cout<<x;
	cin>>y;
	return y;		//return the user enter data
}

int form(){
int a,sa,h,ha;
string n,ci,cn,ad,con,dob,sc,ocp,wh;
float am;

cout<<"\t\t\t\t----------------------------------"<<endl;
cout<<"\t\t\t\t\t>>> Zakat Form <<<"<<endl;
cout<<"\t\t\t\t----------------------------------"<<endl<<endl;
//calling of getpersonaldatadata function
string name = getpersonaldatadata("\t\t\t\tEnter your name : ",n);
int age = getpersonaldatadata("\n\t\t\t\tEnter your age : ",a);
string dateob = getpersonaldatadata("\n\t\t\t\tEnter your date of birth : ",dob);
string occ = getpersonaldatadata("\n\t\t\t\tEnter Occupaction : ",ocp);
string cini = getpersonaldatadata("\n\t\t\t\tEnter your CNIC : ",cn);
string add = getpersonaldatadata("\n\t\t\t\tEnter your Address : ",ad);
string city = getpersonaldatadata("\n\t\t\t\tEnter your City : ",ci);
string Tel = getpersonaldatadata("\n\t\t\t\tEnter your Telephone : ",con);
//calling of getfinancialdata function 
int salary = getfinancialdata("\n\t\t\t\tEnter your current salary   : ",sa);
int house = getfinancialdata("\n\t\t\t\tEnter number of household Dependents : ",h);
int inc = getfinancialdata("\n\t\t\t\tEnter Gross Household Annual Income : ",ha);
string source = getpersonaldatadata("\n\t\t\t\tEnter Source Zakat or Sadaqa : ",sc);
float amount = getfinancialdata("\n\t\t\t\tEnter Amount : ",am);
string who = getpersonaldatadata("\n\t\t\t\tTo who you want to delivered this amount : ",wh);
 cout<<endl<<endl;
cout<<"\t\t\t\t------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t>>> Thank you for Given your Zakat to us..! <<<"<<endl;
cout<<"\t\t\t\t------------------------------------------------------------"<<endl<<endl;

	return 0;
}
