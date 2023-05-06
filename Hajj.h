#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//CONCEPT OF FRIND CLASS & FRIEND FUNCTION :
//in this program their are two class one is agent and other is client class 
//client class is a friend of class agent  

//============ STRAT OF HAJJ PROGRAM ==============

// forward declaration of friend class
class client;		
//*****************strat Agent class**********************		
class Agent{
	protected:   //Concept of protected Access specifier
		static int AWallet_Amount;	//static data member 
	public:		//Concept of public Access specifier
			Agent(int WAM){ 		//paraimeterized consturctor
				AWallet_Amount=WAM;
				cout<<endl<<"\n\t\t\t\tAmount Updated"<<endl;
			}
			Agent(){        //Default constructor
			}
			//setter of AWallet_Amount
			inline void set_AWallet_Amount(int amount){		//use of inline keyword
				AWallet_Amount=amount;
			}
			//getter of AWallet_Amount
			inline int get_AWallet_Amount(){
				return AWallet_Amount;
			}
		 friend class client;			//concept of friend class
		 friend void formfee(int);		//concept of friend function	
};
//*****************end Agent class**********************		

//Static attributies Iinitializing
int Agent::AWallet_Amount=0;

//*****************strat client class**********************	
class client{
	private:
		static int CWallet_Amount; //static data member 
		public:
			client(){  //defualt constrocutor of clinet class
			}
			void Give_PM(int amount){
				Agent objCall;
				CWallet_Amount -= amount;
				objCall.AWallet_Amount+=amount;
				
			}
			inline int get_CWallet_Amount(){
				return CWallet_Amount;
			}	
			
//defining of friend function in which friend class agent function is use with his data member 					
void formfee(int PayAmount){
	Agent objPay;
	objPay.AWallet_Amount-= PayAmount;
	cout<<endl<<"\t\t\t\t"<<PayAmount<<"Amount of hajj form is Received from your agent"<<endl;
}

//main function in this program in which all above function are called 
void menu() {
	Agent objPm1;
	string name, age, address, cnic, gender; 
	int  c, a, f;
	client ObjGPm;
	cout << "\n\t\t\t\t\t-------------------------------"<<endl;
	cout << "\t\t\t\t\t>> APPLYING FORM <<" << endl;
	cout << "\t\t\t\t\t-------------------------------" <<endl;	
	cout<<endl<<"\t\t\t\tEnter your name : ";
	cin>>name;
	cout<<endl<<"\t\t\t\tEnter your age : ";
	cin>>age;
	cout<<endl<<"\t\t\t\tEnter your gender : ";
	cin>>gender;
	cout<<endl<<"\t\t\t\tEnter your address : ";
	cin>>address;
	cout<<endl<<"\t\t\t\tEnter your CNIC : ";
	cin>>cnic;			
	cout<<endl<<"\t\t\t\tAgent Wallet Amount Was:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tPay 10,000/=  for agent commission : ";
	cin>>a;
	Agent ObjPm(a);
	cout<<endl<<"\t\t\t\tNow Agent Wallet Amount is:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tClient's Wallet Amount Was:" <<ObjGPm.get_CWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tPlease Pay 12000/= to your agent for paper work : ";
	cin>>c; 
	ObjGPm.Give_PM(c);
	cout<<endl<<"\t\t\t\tClient's Wallet Amount is:"<<ObjGPm.get_CWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tAgent Wallet Amount is:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tYour Agent will Pay 500 for Hajj form : ";
	cin>>f;
	formfee(f);
	cout<<endl<<"\t\t\t\tAgent Wallet Amount is:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\t----------------------------------------------------------------------"<<endl;	
	cout<<endl<<"\t\t\t\tYour application for Hajj is sumitted you will get  replay soon...!!";
	cout<<endl<<"\t\t\t\t-----------------------------------------------------------------------"<<endl;	
}
};
//*****************end client class**********************	
//Static attributies Iinitializing
int  client::CWallet_Amount=150000;
