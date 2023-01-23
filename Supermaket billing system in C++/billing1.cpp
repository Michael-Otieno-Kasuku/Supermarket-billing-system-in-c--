#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

class shopping{
	private:
		int pcode;
		float price;
		float d;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void reciept();
};

void shopping::menu(){
	m://this is a label
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t-----------------------------------\n";
	cout<<"\t\t\t\t                                   \n";
	cout<<"\t\t\t          Supermarket main menu       \n";
	cout<<"\t\t\t\t                                    \n";
	cout<<"\t\t\t\t------------------------------------\n";
	cout<<"\t\t\t\t|  1) Administrator |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t|  2) Buyer         |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t|  3) Exit          |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\n\t\t\tPlease select!";
	cin>>choice;
	system("CLS");
	switch(choice){
		case 1:
			cout<<"\t\tPlease Login \n";
			cout<<"\t\t\tEnter email \n";
			cin>>email;
			cout<<"\t\t\tPassword     \n";
			cin>>password;
			
			if(email=="mokasuku@gmail.com"&&password=="mokasuku"){
				system("CLS");
				cout<<"********Login Successful******";
				getch();
				administrator();
			}
			else
			{
				cout<<"Invalid email/password";
			}
			break;
		case 2:
			buyer();
			break;
		case 3:
			exit(0);
			break;
		default:
			{
				cout<<"Please select from the given options";
			}
	}
	goto m;
}

void shopping::administrator(){
	m:
	int choice;
	cout<<"\n\n\n\t\t\tAdministrator menu";
	cout<<"\n\t\t\t|--------1) Add the product -------|";
	cout<<"\n\t\t\t|                                  |";
	cout<<"\n\t\t\t|--------2) Modify the product-------|";
	cout<<"\n\t\t\t|                                  |";
	cout<<"\n\t\t\t|--------3) Delete the product -------|";
	cout<<"\n\t\t\t|                                  |";
	cout<<"\n\t\t\t|--------4) Back to main menu -------|";
	
	cout<<"\n\n\tPlease enter your choice";
	cin>>choice;
	
	switch(choice){
		case 1:
			add();
			break;
	    case 2:
	    	edit();
	    	break;
	    case 3:
	    	rem();
	    case 4:
	    	menu();
	    	break;
	    default:
	    	cout<<"Invalid choice";
	}
	goto m;
}

void shopping::buyer(){
	m:
	int choice;
	cout<<"\t\t\t Buyer \n";
	cout<<"---------------------";
	cout<<"                  \n";
	cout<<"\t\t\t 1) Buy product \n";
	cout<<"                  \n";
	cout<<"\t\t\t 1) Go back \n";
	cout<<"                  \n";
	cout<<"\t\t\tEnter your choice";
	cin>>choice;
	
	switch(choice){
		case 1:
			reciept();
			break;
	    case 2:
	    	menu();
	    	break;
	    default:
	    	cout<<"Invalid choice";
	}
	goto m;
}
void shopping::add(){
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\tAdd new product";
	cout<<"\n\n\tProduct code of the product";
	cin>>pcode;
	cout<<"\n\nName of the product";
	cin>>pname;
	cout<<"\n\n\tPrice of the product";
	cin>>price;
	cout<<"\n\n\tDiscount on the product";
	cin>>d;
	
	data.open("database.txt",ios::in);//opening the file in reading mode
	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data<<"  "<<pcode<<" "<<pname<<" "<<price<<" "<<d<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;//initializing the index of file
		
		while(!data.eof()){
			if(c==pcode){
				token++;
			}
			data>>c>>n>>p>>d;//for iteration
		}
		data.close();
	if(token==1){
		goto m;
	}
	else{
		data.open("database.txt",ios::app|ios::out);//opening the file in append and writing mode
		data<<"  "<<pcode<<" "<<pname<<" "<<price<<" "<<d<<"\n";//writing in the file
		data.close();
	}
	}
	cout<<"\n\n\t\tRecord inserted";
}

void shopping::edit(){
	fstream data, data1;//bjects of the fstream class
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\tModify the record";
	cout<<"\n\n\tProduct code : ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"File doesn't exist";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>d;
		while(!data.eof()){
			if(pkey==pcode){
				cout<<"\n\t\tProduct new code : ";
				cin>>c;
				cout<<"\n\nName of the product : ";
				cin>>pname;
				cout<<"\n\n\tPrice";
				cin>>p;
				cout<<"\n\n\tDiscount ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\\t\tRecord edited";
				token++;
			}else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<d<<"\n";
			}
			data>>pcode>>pname>>price>>d;//so that the while loop can iterate
		}
		data.close();
		data1.close();
		
		remove("database.txt"); //to remove all the list in the file
		rename("database1.txt","database.txt");//to rename the file
		
		if(token==0){
			cout<<"Record not found sorry";
		}
	}
}

void shopping::rem(){
	fstream data, data1;
	int pkey;
	int token=0;
	cout<<"\n\n\tDelete product";
	cout<<"\n\n\tProduct code : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"File doesn't exist";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>d;//this is how we read from the file in order to iterate the while loop
		while(!data.eof()){
			if(pcode==pkey){
				cout<<"\n\n\tProduct deleted successfully";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<d<<"\n";
			}
			data>>pcode>>pname>>price>>d;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1,txt","database.txt");
		
		if(token==0){
			cout<<"\n\nRecord not found";
		}
	}
}
void shopping::list(){
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n--------------------------------------------------------------\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n--------------------------------------------------------------\n";
	data>>pcode>>pname>>price>>d;
	while(!data.eof()){
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>d;//for iteration purpose
	}
	data.close();
}

void shopping::reciept(){
	//here we have to use arrays because willl store multiple product keys
	fstream data;
	int arrc[100];//array of codes
	int arrq[100];//array of quantity
	char choice;
	int c = 0;//counter variable
	float amount = 0;
	float discount = 0;
	float total;
	
	cout<<"\n\n\t\t\tRECIEPT";
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\nEmpty database";
	}
	else{
		data.close();
		list();
		cout<<"------------------------------------------------------------\n";
		cout<<"\n                                                           \n";
		cout<<"\n             Please place the order                        \n";
		cout<<"\n                                                           s\n";
		cout<<"------------------------------------------------------------\n";
		//we use do while loop because we have to run a specific part of the loop and the ther part we have to run based on the choice
		do{
			m:
			cout<<"\n\nEnter product code : ";
			cin>>arrc[c];
			cout<<"\n\nEnter the quantity: ";
			cin>>arrq[c];
			for(int i=0;i<c;i++){
				if(arrc[c]==arrc[i]){
					cout<<"\n\nDuplicate product code. Please try again";
					goto m;
				}
			}
			c++;//if the product code is not duplicate
			cout<<"\n\nDo you want to buy another product or not if yes press y else n";
			cin>>c;
		}while(choice=='y');
		
		cout<<"\n\n\t\t\t-------------------------------------RECIEPT-------------------------\n";
		cout<<"\nProductNo\tProduct Name\tProduct quantity\tPrice\tAmount\tAmount with discount\n";
		for(int i=0;i<c;i++){
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>d;
			while(!data.eof()){
				if(pcode==arrc[i]){
					amount=price+arrq[i];
					d = amount - (amount*d/100);
					total = total+d;
					cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<d;
				}
				data>>pcode>>pname>>price>>d;
			}
		}
		data.close();
	}
	cout<<"\n\n---------------------------------------";
	cout<<"\nTotal amount: "<<total;
	
}

int main(){
	shopping s;
	s.menu();
}
