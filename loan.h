#include <iostream>
#include <string>

using namespace std;
//CONCEPT OF NESTED STRUCTURE:
//In this program their is a National_record in which it member data & function are
//present in this struct then there are three diffrerent struct named Personal_information,
//Professional_information & Bank_information are nested inside the National_record.

//========================= Start OF National_record ========================================
//National record
struct National_record{
	char Nationality[20];
	char Gender[20];
	int Cnic;
	char Religion[20];
	char name[20];

void waitForEnter(){
    cout << "\n\t\t\tPress enter to go back: ";
    cin.get();
}
void getloan();

//Personal information
struct Personal_information{
char email[20];
char address[20];
char Education[20];
int age;
int phone_number;
};

//Professional information 
struct Professional_information{
float salary;
int ID;
char company_name[20];
int working_experience;
int working_hours;
};

//Bank information
struct Bank_information{
int Acc_number;
char ac_email[20];
char Bank_name[20];
int balance;
int credit_card;
int lamount;
string Reason;
string till;
string when;
};

struct Personal_information Pers;
struct Professional_information Prof;
struct Bank_information Acinfo;
};

//};
//========================= END OF National_record ========================================

//member function of National_record

void National_record::getloan(){
National_record nat[2];
int i;
for(i=0;i<1;i++){
system("cls");
//National record of client
cout << "\n\t\t\t\t\t-------------------------------" << endl;
cout << "\t\t\t\t\t\t>> APPLYING FORM <<" << endl;
cout << "\t\t\t\t\t-------------------------------" << endl;
cout<<endl;
cout<<"\t\t\t\tEnter Name : ";
cin>>nat[i].name,19;
cout<<endl;
cout<<"\t\t\t\tEnter CNIC : ";
cin>>nat[i].Cnic;
cout<<endl;
cout<<"\t\t\t\tEnter Gender : ";
cin>>nat[i].Gender,19;
cout<<endl;
cout<<"\t\t\t\tEnter Nationality : ";
cin>>nat[i].Nationality,19;
cout<<endl;
cout<<"\t\t\t\tEnter Religion : ";
cin>>nat[i].Religion,19;
cout<<endl;
//Personal information of client

cout<<"\t\t\t\tEnter address : ";
cin>>nat[i].Pers.address,19;
cout<<endl;
cout<<"\t\t\t\tEnter Age : ";
cin>>nat[i].Pers.age;
cout<<endl;
cout<<"\t\t\t\tEnter Education : ";
cin>>nat[i].Pers.Education,19;
cout<<endl;
cout<<"\t\t\t\tEnter Email : ";
cin>>nat[i].Pers.email,19;
cout<<endl;
cout<<"\t\t\t\tEnter Phone number : ";
cin>>nat[i].Pers.phone_number;
cout<<endl;
//Professional information of client

cout<<"\t\t\t\tEnter Business ID : ";
cin>>nat[i].Prof.ID;
cout<<endl;
cout<<"\t\t\t\tEnter Working experience : ";
cin>>nat[i].Prof.working_experience;
cout<<endl;
cout<<"\t\t\t\tEnter Company name : ";
cin>>nat[i].Prof.company_name,19;
cout<<endl;
cout<<"\t\t\t\tEnter working hours : ";
cin>>nat[i].Prof.working_hours;
cout<<endl;
cout<<"\t\t\t\tEnter salary : ";
cin>>nat[i].Prof.salary;
cout<<endl;
//Bank Information of Client

cout<<"\t\t\t\tEnter Account number : ";
cin>>nat[i].Acinfo.Acc_number;
cout<<endl;
cout<<"\t\t\t\tEnter Bank name : ";
cin>>nat[i].Acinfo.Bank_name,19;
cout<<endl;
cout<<"\t\t\t\tEnter Balance : ";
cin>>nat[i].Acinfo.balance;
cout<<endl;
cout<<"\t\t\t\tEnter Bank email : ";
cin>>nat[i].Acinfo.ac_email,19;
cout<<endl;
cout<<"\t\t\t\tEnter ATM card number : ";
cin>>nat[i].Acinfo.credit_card;
cout<<endl;
cout<<"\t\t\t\tEnter Reason For Applying : ";
cin>>nat[i].Acinfo.Reason;
cout<<endl;
cout<<"\t\t\t\tEnter Loan amount: : ";
cin>>nat[i].Acinfo.lamount;
cout<<endl;
cout<<"\t\t\t\tEnter number of years for returing : ";
cin>>nat[i].Acinfo.till;
cout<<endl;
cout<<"\t\t\t\tEnter Date when you want:";
cin>>nat[i].Acinfo.when;
cout<<endl;
double Total = nat[i].Prof.salary/nat[i].Prof.working_hours;

cout<<endl<<endl;

cout<<"\t\t\t\tYour Appliction for loan is approved"<<endl;
cout<<"\t\t\t\tYour total monthly payment is: $" <<Total<<endl;
cout<<"\t\t\t\tYour have to pay this monthly payment in every first date of every month..."<<endl;
cout<<endl<<"\t\t\t\t-------------------------------------------"<<endl;	
cout<<endl<<"\t\t\t\tYour application for loan is approved..!!";
cout<<endl<<"\t\t\t\t-------------------------------------------"<<endl;

cin.get();

nat[i].waitForEnter();
}
}
//National Record
void showloandata(){
National_record nat[2];
int i;

cout<<"------------------------------------------"<<endl;
cout<<"\t\t\tNational Record\t\t"<<endl;
cout<<"------------------------------------------"<<endl;

cout<<"Name\t"<<"CNIC\t"<<"Gender\t"<<"Nationality\t"<<"Religion\t"<<endl;
for(i=0;i<1;i++){
cout<<nat[i].name<<"\t"<<nat[i].Cnic<<"\t"<<nat[i].Gender<<"\t"<<nat[i].Nationality<<"\t"<<nat[i].Religion<<endl;
}
//Personal record
cout<<"----------------------------------------------------------------"<<endl;
cout<<"\t\tPersonal Record\t\t"<<endl;
cout<<"----------------------------------------------------------------"<<endl;

cout<<"Address\t\t"<<"Age\t\t"<<"Education\t\t"<<"Email\t\t"<<"Phone number"<<endl;
for(i=0;i<1;i++){
cout<<nat[i].Pers.address<<"\t"<<nat[i].Pers.age<<"\t"<<nat[i].Pers.Education<<"\t"<<nat[i].Pers.email<<"\t"<<nat[i].Pers.phone_number<<endl;
}
//Professional record
cout<<"----------------------------------------------------------------"<<endl;
cout<<"\t\tProfessional Record\t\t"<<endl;
cout<<"----------------------------------------------------------------"<<endl;

cout<<"Business ID\t\t"<<"Working experience\t\t"<<"Company name\t\t"<<"Working hour\t\t"<<"Salary"<<endl;
for(i=0;i<1;i++){
cout<<nat[i].Prof.ID<<"\t\t"<<nat[i].Prof.working_experience<<"\t\t"<<nat[i].Prof.company_name<<"\t\t"<<nat[i].Prof.working_hours<<"\t\t"<<nat[i].Prof.salary<<endl;
}
//Bank record
cout<<"----------------------------------------------------------------"<<endl;
cout<<"\t\tBank Record\t\t"<<endl;
cout<<"----------------------------------------------------------------"<<endl;

cout<<"Account number\t\t"<<"Bank name\t\t"<<"Balance\t\t"<<"Bank email\t\t"<<"ATM card"<<endl;
for(i=0;i<1;i++){
cout<<nat[i].Acinfo.Acc_number<<"\t\t"<<nat[i].Acinfo.Bank_name<<"\t\t"<<nat[i].Acinfo.balance<<"\t\t"<<nat[i].Acinfo.ac_email<<"\t\t"<<nat[i].Acinfo.credit_card<<endl;
}
cout<<"Account number\t\t"<<"Bank name\t\t"<<"Balance\t\t"<<"Bank email\t\t"<<"ATM card"<<endl;
for(i=0;i<1;i++){
cout<<nat[i].Acinfo.Acc_number<<"\t\t"<<nat[i].Acinfo.Bank_name<<"\t\t"<<nat[i].Acinfo.balance<<"\t\t"<<nat[i].Acinfo.ac_email<<"\t\t"<<nat[i].Acinfo.credit_card<<endl;
}

}


