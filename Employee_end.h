#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "loan.h"
#include "insurance.h"

using namespace std;

//=======================Start of Employee Class================== 
class Employee_management{
private:				//Concept of Private Access specifier
    // Variables for employee details
    typedef unsigned int e_int;		//typedef: create the userdefine datatype  
    char name[30];
    char id[5];
    char designation[10];
    e_int age, ctc, CNIC;
    char experience[20];

public:  		//Concept of Public Access specifier

//	Employee_management(int a, int c) { 
//		age = a; ctc = c;			// Concept of Parameterized constructor
//	 }
//    
//    Employee_management(const Employee_management &e1) {
//	age = e1.a; 					// Concept of Copy constructor
//	ctc = e1.c;
//	}
// 
//  inline int getage(){ 
//	return age; 
//	}
//  inline  int getctc(){
//	  return ctc; 
//	}

// All Members Function of class Employee_management are defined here:
	virtual void menu();
    virtual void waitForEnter();
    virtual void insert();
    virtual void display();
    virtual void modify();
    virtual void search();
    virtual void deleted();
};
//======================= END of Employee Class ================== 

//Employee_management class Menu
void Employee_management::menu(){ 
    while (true)
    {
        e_int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> EMPLOYEES_END SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t\t\t 6. Apply For staff Loan" << endl;
        cout << "\t\t\t\t\t 7. Apply For Insurance" <<endl;
        cout << "\t\t\t\t\t 8. Exit" << endl;

        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options: [1/2/3/4/5/6/7/8] <<" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:{
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            waitForEnter();
			break;
		}
        case 2:{
            display();
            break;
        }
        case 3:{
            modify();
            break;
        }
        case 4:{
            search();
            break;
			}
        case 5:{
            deleted();
            break;
			}
        case 6:{
            National_record n;
			n.getloan();
            break; 
		}
        case 7:{
            system("cls");
			Insurance i;
			i.meun();
			break;	
			}
        case 8:{
            system("cls");
            cout << "\n\n\ns\t\t\t>> Have a nice day...Thank you!! <<\n\n";
            Sleep(10);
            exit(0);            
			}
        default:{
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        }
        getch();
    }
}
// add data of employees in file 
void Employee_management::insert() {
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n Enter Designation: ";
    cin >> designation;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee CTC: ";
    cin >> ctc;
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    file.open("Employee_Record.csv", ios::app | ios::out);
    file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
    file.close();
}

// Display data of employees
void Employee_management::display(){
    system("cls");
    e_int total = 1;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
    file.open("Employee_Record.csv", ios::in);
    if (!file){
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else{
        file >> name >> id >> designation >> age >> ctc >> experience;
        cout << "\n -------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      CTC      ||    EXPERIENCE    ||";
        cout << "\n -------------------------------------------------------------------------------------------------";
        while (!file.eof()){
            cout << "\n";
            cout << total++ << ". " << name << "\t  " << id << "\t\t  " << designation << "\t\t   " << age << "\t\t  " << ctc << "\t\t" << experience;
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

// Modify data of in employees file
void Employee_management::modify(){
    system("cls");
    char checkId[5];
    e_int found = 0;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
    file.open("Employee_Record.csv", ios::in);
    if (!file){
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else{
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.csv", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof()){
            if (strcmp(checkId, id) == 0){
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter Designation: ";
                cin >> designation;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee CTC: ";
                cin >> ctc;
                cout<<"\n Enter Employee CNIC: ";
                cin>>CNIC;
                cout << "\n Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
                found++;
            }
            else{
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0){
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.csv");
        rename("record.csv", "Employee_Record.csv");
    }
    waitForEnter();
}

// Search data of employees Displays all details according to Employee's id
void Employee_management::search(){                                  
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    file.open("Employee_Record.csv", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    if (!file){
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else{
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof()){
            if (strcmp(checkId, id) == 0){
                cout << "\n---------------------\n";
                cout << "Employee Name: " << name << "\n";
                cout << "Employee ID.: " << id << "\n";
                cout << "Employee Designation: " << designation << "\n";
                cout << "Employee Age: " << age << "\n";
                cout << "Employee CTC: " << ctc << "\n";
                cout << "Employee Experience: " << experience << "\n";
                cout << "---------------------\n";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

// Delete data of employees from file record.
void Employee_management::deleted(){
    system("cls");
    char checkId[5];
    fstream file, file1;
    e_int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    file.open("Employee_Record.csv", ios::in);
    if (!file){
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else{
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.csv", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof()){
            if (strcmp(checkId, id) != 0){
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            else{
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0){
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.csv");
        rename("record.csv", "Employee_Record.csv");
        waitForEnter();
    }
}

void Employee_management::waitForEnter(){
    cout << "\n\nPress enter to go back: ";
    cin.get();
}

// Employee Authentication
int password_user(){
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    system("cls");
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\t\t\t||  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\n\t\t\t   -| Press: [1] Register & [2] Login  |-";
    int selection;
    cout << "\n\nPlease Enter Value: ";
    cin >> selection;
    // if user press [1], then it would go to register.
    if (selection == 1){
        system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> REGISTRATION EMPLOYEE <<";
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name_reg;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        file.open("Ep_data.csv", ios::app);
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\nRegistration Succesfully save";
        getch();
        password_user();
    }
    // if user press [2], then it would go to login.
    else if (selection == 2)
    {
        system("cls");
        file.open("Ep_data.csv", ios::in);
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\t\t\t\t\t>> EMPLOYEE LOGIN <<";
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Granted..\n\n";
                system("PAUSE");
                system("cls");
            }
            else
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Aborted...\n\n";
                system("PAUSE");
                system("cls");
                password_user();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        password_user();
    }
    return 0;
}
