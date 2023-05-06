#include <iostream>
#include<fstream>
#include <limits>
#include <string.h>
#include <unistd.h>
#include <windows.h> //for system cls and sleep and goto back: functions. 
#include <conio.h>   // for get function

//=======================Start of Bank Class================== 
using namespace std;

class Bank{		//concept of Abstract Class and Pure Virtual function	
	public:				
	virtual void showData(void) = 0;  
};
//=======================End of Bank Class==================


//=======================Start of class atm==============================
class atm{				//Concept of Class
 public:			//Concept of Private Access specifier
	char username[30];
	int password;
	static int balance;	//Concept of static.
	
public:				//Concept of Public Access specifier	
//	atm(string un,int pass){	//Concept of Parameterized Constructor 
//	username = un;
//	password = pass;	
//	}
//	~atm(){}				//Concept of distructor
	
//getter for username
	inline char* usernames(void){		   //Use of inlilne function 
		return  username;
	}

//getter for password
	inline int passwords(void){	
		return password;
	}

// Function to set the data (setter)
	void setData(void){ 						
		cout << "\n\t\t\t\t-------------------------------"<<endl;
		cout << "\t\t\t\t\t>> APPLYING FORM <<" << endl;
		cout << "\t\t\t\t-------------------------------" <<endl;	
		cin.ignore(numeric_limits<streamsize>::max(),'\n');    //This line ignores the rest of the current line, up to '\n'
		cout << "\n\t\t\tEnter username:";
		cin.getline(username, 30);		//using getline function to take input from user
		cout << "\n\t\t\tEnter 4-digit password:";
		cin >> password;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "\n\t\t\tEnter initial balance:";
		cin >> balance;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}

	void showData(void){							// Function displaying the data (getter)
		cout << "\t\t\tUsername:" << username<<endl;
		cout << "\t\t\tPassword:" << password<<endl;
		cout << "\t\t\tBalance:" << balance<<endl;
	}

// All Members Function of class atm are defined here	
	void atmUser();
	int add_user();												
	int view_all_users();
	int delete_user(char*);
	void update_user_as_deposit(char*);
	void update_user_as_withdraw(char*);
	int search_specific_user(char*, int);
	int search_all_user_to_display(char*);
};
//=======================End of class atm==============================


//Static attributies Iinitializing
int atm::balance=0;


//===========Start Defining all Members Function of class atm-====================
void atm::atmUser(){
	atm a;
	char uname[30];
	int pass, ch, ch1, ch2, found = 0;

mainmenu:
	 system("cls");
	cout<<"\n\n\t\t\t\t===================================\n";
	cout<<"\t\t\t\t\t|    WELCOME TO ATM  |";
	cout<<"\n\t\t\t\t====================================\n";
    cout<<endl<<endl;
	cout<<"\t\t\t\t   :: :: MAIN MENU :: ::\n";
    cout<<endl;
	cout<<"\n\n\t\t\t\t1. ADMIN";
	cout<<"\n\t\t\t\t2. CUSTOMER";
	cout<<"\n\t\t\t\t3. EXIT";
	cout<<"\n\n\t\t\t\tChoose options:[1/2/3] :: ";
	cin >> ch;

	switch (ch) {
	case 1:
	rerun:
		 system("cls");
		cout << "\n\t\t\t\tEnter details to login as Admin..!!\n";
		cout << "\n\t\t\t\tEnter password for security Purposes : ";
		cin >> pass;
		if (pass == 1234) {
		admin:
			 system("cls");
			cout<<"\n\t\t\t\t-------------------------------"<<endl; 
			cout << "\t\t\t\t>>Welcome to Admin Menu..!<<";
			cout<<"\n\t\t\t\t-------------------------------\n"; 
 cout<<endl<<endl;
	cout<<"\n\n\t\t\t\t1. ADD USER";
	cout<<"\n\t\t\t\t2. DELETE USER";
	cout<<"\n\t\t\t\t3. VIEW USER";
	cout<<"\n\t\t\t\t4. EXIT";
	cout<<"\n\n\t\t\t\tChoose options:[1/2/3/4] :: ";
			cin >> ch1;
			switch (ch1) {
			case 1:
				a.add_user();
				goto admin;

			case 2:
				cout << "\n\t\t\t\tEnter the Username to be deleted : "<<endl;
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cin.getline(uname, 30);
				a.delete_user(uname);
				goto admin;

			case 3:
				a.view_all_users();
				 sleep(4);
				goto admin;

			case 4:
				break;
			}
		}
		else {
			cout << "\n\t\t\t\tDetails are incorrect ! Please try again.....";
			cin.get();
			goto rerun;
		}
		goto mainmenu;

	case 2:
		system("cls");
		cout << "\n\t\t\t\tEnter details to login as User\n";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "\t\t\t\tEnter username:";
		cin.getline(uname, 30);
		cout << "\n\t\t\t\tEnter password:";
		cin >> pass;
		found = a.search_specific_user(uname, pass);
		if (found) {
		user:
			system("cls");
			cout<<"\n\t\t\t\t-------------------------------"; 
			cout << "\n\t\t\t\t>>Welcome to Uesr Menu..!<<"<<endl;
			cout<<"\t\t\t\t-------------------------------\n"; 
			cout<<"\n\n\t\t\t\t1. DEPOSITE";
			cout<<"\n\t\t\t\t2. WITHDRAW";
			cout<<"\n\t\t\t\t3. VIEW ACCOUTN";
			cout<<"\n\t\t\t\t4. EXIT";
			cout<<"\n\n\t\t\t\tChoose options:[1/2/3/4] :: ";			
			cin >> ch2;
			switch (ch2) {
			case 1:
				a.update_user_as_deposit(uname);
				goto user;
			case 2:
				a.update_user_as_withdraw(uname);
				goto user;
			case 3:
				a.search_all_user_to_display(uname);
				 sleep(4);
				goto user;
			case 4:
				cout << "\nThank you";
				break;
			}
		}
		else {
			cout << "\nNo account found with username "<<uname;
			cin.get();
		}
		goto mainmenu;

	case 3:
		cout << "\n\tThankyou for banking with us";
		cin.get();
		break;
	}
}

//ADDING DATA OPERACTION IN FILEING

int atm::add_user(){			// Function to add new recourd of new user
	atm a;
	ofstream file1;	
	file1.open("atm.csv",ios::out | ios::app);		// Open file in write mode
	if (!file1) {
		cout << "Error in creating file.." << endl;
		return 0;
	}
	a.setData();			// Read from user
	file1.write((char*)&a, sizeof(a));			// Write into file
	file1.close();
	return 0;
}

//SEARCHING OPERACTION IN FILEING

int atm::view_all_users(){			// View recourds of all Users
	atm a;
	ifstream file1;
	file1.open("atm.csv", ios::in);
	if (!file1) {
		cout << "\nError in opening file..";
		return 0;
	}
	file1.read((char*)&a, sizeof(a));  			// Read data from file
	while (!file1.eof()) {	
		a.showData();							// Display data on screen
		file1.read((char*)&a, sizeof(a));
	}
	file1.close();
	return 0;
}

//DELETE OPERACTION IN FILEING

int atm::delete_user(char* uname){			// Function to delete the user
	atm a;
	fstream original, temp;
	original.open("aaa.csv", ios::in);
	if (!original) {
		cout << "\nFile not found";
		return 0;
	}
	else {
		temp.open("temp.csv",ios::out | ios::app);
		original.read((char*)&a, sizeof(a));
		while (!original.eof()) {
			if (!strcmp(a.usernames(),uname)) {
				cout << "\nData found and deleted\n"<< a.username<<"\n";
			}
			else {
				temp.write((char*)&a,sizeof(a));
			}
			original.read((char*)&a,sizeof(a));
		}
		original.close();
		temp.close();
		remove("atm.csv");
		rename("temp.csv", "atm.csv");
		a.view_all_users();
	}
	return 0;
}

//EDITING OPERACTION IN deposit FILE

void atm::update_user_as_deposit(char* uname){			// Function to update user by
	atm a;												// depositing money
	fstream file, temp;	
	file.open("aaa.csv",ios::in | ios::out | ios::ate);
	temp.open("temp.csv",ios::out | ios::app);
	file.seekg(0);
	file.read((char*)&a, sizeof(a));
	while (!file.eof()) {				/// sraech Till end of the file by help of .eof()
		if (!strcmp(a.usernames(), uname)) {
			int b;
			cout << "\nEnter amount to deposit:";
			cin >> b;
			a.balance = a.balance + b;
			cout << "\nBalance is:"<< a.balance;
			temp.write((char*)&a, sizeof(a));
		}
		else {
			temp.write((char*)&a, sizeof(a));
		}
		file.read((char*)&a, sizeof(a));
	}
	file.close();
	temp.close();
	remove("atm.csv");
	rename("temp.csv", "atm.csv");
}

//EDITING OPERACTION IN withdraw FILE

void atm::update_user_as_withdraw(char* uname){					// Function to update user by
	atm a;												// depositing withdrawing user givcen amount				
	fstream file, temp;	
	file.open("atm.csv",ios::in | ios::out | ios::ate);
	temp.open("temp.csv",ios::out | ios::app);
	file.seekg(0);
	file.read((char*)&a, sizeof(a));
	while (!file.eof()) {				// Till end of file is reached
		if (!strcmp(a.usernames(), uname)) {
			int b;
			cout << "\nEnter amount to withdraw:";
			cin >> b;
			if (a.balance < b) {
				cout<< "\nInsufficient balance to withdraw";
			}
			else {
				a.balance = a.balance - b;
				temp.write((char*)&a,sizeof(a));
				cout << "\nBalance is:"<< a.balance;
			}
		}
		else {
			temp.write((char*)&a,sizeof(a));
		}
		file.read((char*)&a, sizeof(a));
	}
	file.close();			// Close the file
	temp.close();
	remove("atm.csv");
	rename("temp.csv", "atm.csv");
}

//1->SEARCHING OPERACTION IN FILEING
int atm::search_specific_user(char* uname, int pass){		// Search specific user data
	atm a;
	fstream f;
	f.open("atm.csv", ios::in);			// Open the file
	if (!f) {
		cout << "\nError in opening file..";
		return 0;
	}	
	f.read((char*)&a, sizeof(a));		// Read data from file
	while (!f.eof()) {
		if (!strcmp(a.usernames(), uname)) {
			if (a.passwords() == pass) {
				return 1;
			}
		}
		f.read((char*)&a, sizeof(a));
	}
	f.close();			// Close the file
	return 0;
}

//2->SEARCHING OPERACTION IN FILEING

int atm::search_all_user_to_display(char* uname){ 			// Search all user data
	atm a;
	fstream file1;
	file1.open("atm.csv", ios::in); 		// Open the file
	if (!file1) {
		cout << "\nError in opening file..";
		return 0;
	}                                     // Read data from file
	file1.read((char*)&a, sizeof(a));
	while (!file1.eof()) {
		if (!strcmp(a.usernames(), uname)) {
			a.showData();
			return 0;
		}
		file1.read((char*)&a, sizeof(a));
	}
	// Close the file
	file1.close();
	return 0;
}
//
////===========END Defining all Members Function of class atm-====================

////=======================END OF ATM CLASS==================
