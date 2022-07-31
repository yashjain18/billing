#include<iostream>
#include<fstream>
using namespace std;

class shopping{
	private:
		int pcode;
		float price;
		float discount;
		string pname;
		
	public:
		void menu();
	    void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};
void shopping::menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t__________________________________\n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t      SUPERMARKET MAIN MENU       \n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t__________________________________\n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t|     1) ADMINISTRATOR           |\n";
    cout<<"\t\t\t|                                |\n";
    cout<<"\t\t\t|     2) BUYER                   |\n";
    cout<<"\t\t\t|                                |\n";
    cout<<"\t\t\t|     3) Exit                    |\n";
    cout<<"\t\t\t|                                |\n";
    cout<<"\t\t\t  PLEASE SELECT!!!" ;
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<cout<<"\t\t\t PLEASE LOGIN!!!\n";
        cout<<cout<<"\t\t\t Enter Email    \n";
        cin>>email;
        cout<<cout<<"\t\t\t Enter Password \n";
        cin>>password;

        if(email=="yashnareliya09@gmail.com"&& password=="Yash@2001"){
            administrator();
        }
        else{
            cout<<"Invalid Username Password";
        }
        break;

    case 2:
            buyer();
        break;
    case 3:
        exit(0);

    default:
        cout<<"SELECT FROM GIVEN OPTION";
        break;
    }
goto m;
}

void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t ADMINISTRATOR MEMU";
    cout<<"\n\n\n\t\t\t 1) Add The Product";
    cout<<"\n\n\n\t\t\t|                  |";
    cout<<"\n\n\n\t\t\t 2)Modify The Product";
    cout<<"\n\n\n\t\t\t|                  |";
    cout<<"\n\n\n\t\t\t 3)Delete The Product";
    cout<<"\n\n\n\t\t\t|                  |";
    cout<<"\n\n\n\t\t\t 4)Back To Main Menu";
    cout<<"\n\n\t Please enter the choice"; 
    cin>>choice;

    switch (choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Invalid Choice";
    }
    goto m;
}

void shopping ::buyer(){
    m:
    int choice;
    cout<<"\t\t\t  Buyer \n";
    cout<<"_____________________\n";
    cout<<"\t\t\t 1) Buy Product \n";
    cout<<"                 \n";
    cout<<"\t\t\t 2) Go Back \n";
    cout<<"Enter the choice";
    cin>>choice;

    switch (choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"Invalid Choice";
            break;
    }
    goto m;
}

void shopping::add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float dis;
    string n;

    cout<<"\n\t\t\t Add New Product";
    cout<<"\n\t\t\t Product Code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>> pname;
    cout<<"\n\n\t Price of the product ";
    cin>> price;
    cout<<"\n\n\t Discount Of the Product ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n ";
        data.close();
    }
    else{
        data>>c>>n>>p>>dis;

        while (!data.eof()){
            if (c==pcode){
                token++;
            }    
            data>>c>>n>>p>>dis;
        }
        data.close();
    }
    if (token==1){
        goto m;
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n ";
        data.close();
    }
    cout<<"\n\n\t\t Record Inserted";
}

void shopping ::edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float dis;
    float p;
    string n;

    cout<<"\n\n\t\t Modify Record ";
    cout<<"\n\n\t\t Product Code";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if (!data){
        cout<<"File Does Not Exist";
    }
    else{
        data1.open("databse.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\n\t\t Product New Code";
                cin>>c;
                cout<<"\n\n\t\t Name Of the Product";
                cin>>n;
                cout<<"\n\n\t\t Product Price";
                cin>>p;
                cout<<"\n\n\t\t Discount";
                cin>>dis;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<dis<<"\n";
                cout<<"\n\n\t\t Record Edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
   
        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token==1){
            cout<<"Record Not Forund";
        }
    }
}
void shopping ::rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File Does Not Exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof()){
            if (pcode==pkey){
                cout<<"\n\n\t Product Deleted";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("databse.txt");
        rename("database1.txt","database.txt");
        if (token==0){
            cout<<"Record Not Found";
        }
    }
}
void shopping::list(){
    fstream data;
    data.open("database",ios::in);
    cout<<"\n\n|_____________________________________\n";
    cout<<"proname\t\tName\t\tPrice\n";
    cout<<"\n\n|_____________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
    
void shopping receipt(){
    m:
    fstream data;
    int arrc[100];
    inr arrq[100];
    char choice;
    int c=0;
    float amount;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t RECEIPT";
    data.open("database",ios::in);
    if(!data){
        cout<<"\n\nEmpt Database"
    }
    else{
        data.close();
        list();
            cout<<"\t\t\t__________________________________\n";
            cout<<"\t\t\t                                  \n";
            cout<<"\t\t\t      PLEASE PLACE THE ORDER      \n";
            cout<<"\t\t\t                                  \n";
            cout<<"\t\t\t__________________________________\n";

        do{
            cout<<"Enter Product Code";
            cin>>arrc[c];
            cout<<"\n\nEnter The Product Quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\nDuplicate product code. Please try Again";
                        goto m;
                }
            }
            c++; 
            cout<<"\n\nDo you want to buy anotehr product or not if yes press y else n";
            cin>>choice;
        }while (choice=="y")
            
        cout<<"\n\n\t\t\t_____________________RECEIPT______________________";
        cout<<"\nProduct No. \t Product Name\tproduct Quantity\t Amount With Discount";
        for(int i =0 i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
        cout<<"\n\n_______________________________"; 
        cout<<"\n Total Amount:"<<total;
    }
}
int main(){
    shopping s;
    s.menu;
}

