//Assalamoalikum sir For Log-in 	
//Username : Mustafa
//password : 1234 

//===================== Start of Header Files ================

#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip> // It defines the manipulator functions setbase() , setfill() and setw()
#include<time.h>  // time() function in C++ returns the current calendar time as an object of type time_t
#include<stdlib.h> // It includes functions involving memory allocation, process control, conversions
#include<ctype.h>  //declares a set of functions to classify (and transform) individual characters. For example, isupper()
#include<process.h>
#include<string.h>
#include<windows.h>
#include "ATM.h"
#include "Employee_end.h"
#include "paybill.h"
#include "Hajj.h"
#include "zakat.h"
//#include "insurance.h"
//#include "loan.h"

//======================== End of Header Files =================

using namespace std;

enum week{Sunday , Monday, Tuesday, Wednesday, Thursday,Friday, Saturday};	  //Concept of enum	
enum month{January, Febuary, March, April, May, June, July, August, September, October, November, December};

//Concept of INHERITANCE.
//=======================Start of ACCOUNT Class================== 

class account:public Employee_management, public pay_gas_bill{
private:		//Concept of Private Access specifier

	unsigned int accNo;			//Concept of Objects
	char name[50];
	static int deposit;			//Concept of static.
	char type;
public:			//Concept of Public Access specifier
	
//Concept of default Constructors	
	account(){		
	}
//Concept of default Destructor	
	~account(){		
	}	
	
// All Members Function of class account are defined here		
	const int* const MainMenu();
	void createAccount();
	void displayAccount() const;
	void modify();
	void dep(int);
	void draw(int);					//CONCEPT OF ENCAPSULATION.
	void report() const;
	int retaccNo() const;
	int retdeposit() const;			//using const keyword 
	char rettype() const;
}; 
//=======================END of ACCOUNT Class================== 

//Static attributies Iinitializing
int account::deposit=0;

//=====================START DELECARATION OF ACCOUNT MEMBERS FUNCTION ==================
 
//This FUnction is used to create an Account of User.
void account::createAccount(){ 			
	system("cls");
	cout << "\n\t\t\t\t-------------------------------"<<endl;
	cout << "\t\t\t\t\t>> APPLYING FORM <<" << endl;
	cout << "\t\t\t\t-------------------------------" <<endl;	
	cout<<endl;
	cout<<"\t\t\tPlease enter your Account No. : ";
	cin>>accNo;
	cout<<endl<<endl;
	cout<<"\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<endl;
	cout<<"\t\t\tEnter Type of the Account (C(Current)/S(Savings)) : ";
	cin>>type;
	type=toupper(type);
	while (type != 'S' && type != 'C') {
        cout <<"\t\t\tPlease enter either S or C to avoid data corruption: ";
		cin.clear();
		fflush(stdin);
        cin >> type;
        type = toupper(type);
    }
	cout<<endl;
	cout<<"\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<endl<<endl;
	cout<<"\t\t\tAccount Created..";
}

//This FUnction is used to display an Account of User.
void account::displayAccount() const{
	cout << "\n\t\t\t\t\t------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t>> ACCOUNTS DETAIL <<" << endl;
	cout << "\t\t\t\t\t--------------------------------------" <<endl;	
	cout<<"\n\t\t\tAccount No. : "<<accNo;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}

//This FUnction is used to Modify an Account of User.
void account::modify(){
	cout << "\n\t\t\t\t\t----------------------------------"<<endl;
	cout << "\t\t\t\t\t\t>> MODIFY ACCOUNT  <<" << endl;
	cout << "\t\t\t\t\t------------------------------------" <<endl;	
	cout<<"\n\t\t\tAccount No. : "<<accNo;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}

inline void account::dep(int x){ 	//getter for deposite
	deposit+=x;
}

inline void account::draw(int x){	//getter for widthraw
	deposit-=x;
}

inline void account::report() const{		//this function display the report of all accounts
	cout<<accNo<<setw(10)<<"  "<<name<<setw(10)<<" "<<type<<setw(6)<<"  "<<deposit<<endl; //setw=set width
}

inline int account::retaccNo() const{	//getter for widthraw account number 	
	return accNo;
}

inline int account::retdeposit() const{	 //getter for redeposite
	return deposit;
}

inline char account::rettype() const{  //getter for type of account
	return type;
}

//CONCEPT OF FILE HANDLING 

//CONCEPT OF IN FILE 
void accountDetails(){				
	account ac;
	ofstream outFile;
	outFile.open("account.csv",ios::binary|ios::app);
	ac.createAccount();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//CONCEPT OF OUT FILE 
void display_sp(int n){	
	account ac;
	bool flag=false;			//using bool keyword
	ifstream inFile;
	inFile.open("account.csv",ios::binary);
	if(!inFile){
		cout<<"\nFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		if(ac.retaccNo()==n){
			ac.displayAccount();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false){
        cout<<"\n\n\t\t\tAccount number does not exist";
    }
		
}

//CONCEPT OF SEARCH IN FILING & WRITTING IN FILING
void modifyAccount(int n){			
	bool found=false;
	account ac; 			//Objects of class
	fstream File;
    File.open("account.csv",ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"\nFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false){
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retaccNo()==n){
			ac.displayAccount();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated...!";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found...!";
}

//CONCEPT OF SEARCH IN FILING & DELETEING IN FILING
void deleteAccount(int n){			
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.csv",ios::binary);
	if(!inFile){
		cout<<"\nFile could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.csv",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		if(ac.retaccNo()!=n){
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.csv");
	rename("Temp.csv","account.csv");
	cout<<"\n\n\t\tRecord Deleted ..";
}

//CONCEPT OF OUT FILE TO VIEW
void displayRecords(){		
	system("cls");
	account ac;
	ifstream inFile;
	inFile.open("account.csv",ios::binary);
	if(!inFile){
		cout<<"\nFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type        Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		ac.report();
	}
	inFile.close();
}

//FUNCTION FOR deposit withdraw and storing data in account file.
void deposit_withdraw(int n, int option){
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.csv", ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"\n\n\nFile could not be open!! Press any Key...";
		return;
	}
	while(!File.eof() && found==false){
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retaccNo()==n){
			ac.displayAccount();
			if(option==1){
				//cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2){
				//cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Sorry!! Insufficience balance...";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tSuccess... Record Updated Successfully!!";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tOops! We Couldn't find your record...";
}

//To Display Date on Screen
void date(){
  time_t T= time(NULL);
  struct  tm tm = *localtime(&T); //it can use by time.h header file inn which struct is tm is by default to show date
  cout<<endl<<endl<<endl;
  printf("\t\t\t\t\t   Date :: %02d/%02d/%04d\n\t",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
  
}

//To give delay to load Login System
void delay(unsigned int mseconds){		//it calculate the 24 hours by secound and update the date in display every day
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//If Invalid Attempts will exceed the 3 then 
void callExit(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    fflush(stdin);
    printf("You are out of the System.");
    printf("\n\n");
    printf("\t\t\t\t");
    printf("   Press Enter to Continue Exit Program...");
    getchar();
    exit(0);
}

// Mainpage outlook of the Project
void mainpage(){
  int process=0;
  system("cls");
  system("color 0B");		//D E
  date();
  cout<<endl;
  printf("\t\t\t\t  ------------------------------------\n");
  printf("\t\t\t\t      || BANK MANAGEMENT SYSTEM ||\n");
  printf("\t\t\t\t  ------------------------------------\n");
  cout<<endl<<endl<<endl;
  printf("\t\t\t\t");
  printf("Prepared By    :");
  printf("  Syed Mustafa Hassan");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("Mini Project   :");
  printf("  Bank Management System");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("\n\n");
  printf("\t\t\t\t    Press Enter to continue......");
  printf("\n\n");
  getchar();
  printf("\t\t\t\tLoading");

  for(process=0;process<25;process++){
    delay(150);
    printf(".");
  }
}

// MenuList of Project
void menulist(){
    int ch;
	char my_git;
	int num;
	do{
	system("cls");
	system("color 0E");
	cout<<"\n\n\t\t\t\t==============================\n";
	cout<<"\t\t\t\t|    BANK MANAGEMENT SYSTEM  |";
	cout<<"\n\t\t\t\t==============================\n";
        cout<<endl<<endl;
		cout<<"\t\t\t\t   :: :: MAIN MENU :: ::\n";
        cout<<endl<<endl;
		cout<<"\n\n\t\t\t\t1. Create New Account";
		cout<<"\n\t\t\t\t2. Deposit Amount to Account";
		cout<<"\n\t\t\t\t3. Withdraw Amount from Account";
		cout<<"\n\t\t\t\t4. Balance Enquiry";
		cout<<"\n\t\t\t\t5. Display list of Account holders";
		cout<<"\n\t\t\t\t6. Delete an Account";
		cout<<"\n\t\t\t\t7. Modify the existing Account";
		cout<<"\n\t\t\t\t8. Check Employees Management";
		cout<<"\n\t\t\t\t9. Goto ATM";		//**
		cout<<"\n\t\t\t\t10. Pay Bill";  	//**
		cout<<"\n\t\t\t\t11. Hajj Application Form";//**
		cout<<"\n\t\t\t\t12. Zakat Form";
		cout<<"\n\t\t\t\t13. Apply For loan";
		cout<<"\n\t\t\t\t14. Apply For Insurance";
		cout<<"\n\t\t\t\t15. Exit";
		cout<<"\n\n\t\t\t\tChoose options:[1/2/3/4/5/6/7/8/9/10/11/12/13/14/15] :: ";
		cin>>ch;
		switch(ch){
		case 1:{
			system("cls");
			accountDetails();
			break;}
		case 2:{
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;}
		case 3:{
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		}
		case 4:{
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;}
		case 5:{
			displayRecords();
			break;}
		case 6:{
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deleteAccount(num);
			break;}
		 case 7:{
		 	system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modifyAccount(num);
			break;	 }
		 case 8:{
		 	system("cls");
			Employee_management e; //Concept of Abstraction 
			e.menu();
			break;}
		 case 9:{
		 	system("cls");   
			atm a;					//Concept of Abstraction 
			a.atmUser();
			break;}
        case 10:
        {
        	system("cls");	
			pay_gas_bill *p;
			p->menu();
			break;
			}								
        case 11:
        	{
        	system("cls");	
			client  *c;
			c->menu();
			break;
				}	
        case 12:
        	{
        	system("cls");	
        	form();
			break;
				}				
        case 13:{
        	system("cls");	
        	National_record n;
        	n.getloan();
			break;	
			}			
		 case 14:{
	 	system("cls");
        	Insurance i;
			i.meun();
		break;		
		}
		case 15:{
		 	system("cls");
            cout <<"\n\n\t\t\t\tThanks for using Bank Record System.\n\n";
            cout <<"\n\n\n\n\n\t\t\t\tDo you want to visit my Website [Y/N]: ";
            cin >> my_git;
            my_git = toupper(my_git);
            if (my_git == 'Y') {
                system("start https://github.com/Mustafa-Hassan2001");
            }
            else{
            system("cls");
			cout<<"\n\n\t\t\tThank You... Have a nice day!!";
			exit(0);	
			}
			break;
			}
		 default :{
		 	cout<<"\a";
			break;
		 }
		}
		cin.ignore();
		cin.get();
    }while(ch!=15);
}


//Set Username & Password here for Login System
int logscreen(){	
  char username[30];
  char password[30];
  int chances = 0;
  int flag = 1;
  
  do{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    printf("Username: ");
    scanf("%s",username);
    printf("\t\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t\t");
    printf("Password: ");
    scanf("%s",password);
    if(strcmp(username,"Mustafa")==0 && strcmp(password,"1234")==0)
      {
        printf("\n\n");
        printf("\t\t\t\t");
        printf("You are accessed to the system!\n\n");
        printf("\t\t\t\t   Press Enter to continue...");
        fflush(stdin);
        getchar();
        menulist();
        system("cls");
        getchar();
        flag =0;
      }
      else
      {
        system("cls");
        chances = chances+1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t");
        printf("No. of attempts remain: %d",3-chances);
        fflush(stdin);
        getchar();
        if(chances>=3)
        {

          printf("\t\t\t\t\t\t");
          printf("\n");
          printf("\t\t\t\t");
          printf("   No permission to enter the system!" );
          getchar();
          callExit();
          getchar();
      ;
      }
  } //END OF ELSE
 }
 while(true==1);
}
//=====================END DELECARATION OF ACCOUNT MEMBERS FUNCTION ==================

//============ main function ==========
//Actual Execution Starts here :) Main Function Started
int main(){
	mainpage();
	logscreen();
	return 0;
}
