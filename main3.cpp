#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
void login();
void registration();
void forgot();

int main()
{
    int choice;
    cout<<"\t\t\t\t________________________________________________________\n\n\n";
    cout<<"\t\t\t\t__________________WELCOME TO THE LOGIN PAGE______________\n\n\n";
    cout<<"\t\t\t\t__________________________MENU____________________________\n\n";
    cout<<"                                                                   \n\n";
    cout<<"\t| Press 1 To  Login.                  |"<<endl;
    cout<<"\t| Press 2 To  Register.               |"<<endl;
    cout<<"\t| Press 3 To  Recover Password.       |"<<endl;
    cout<<"\t| Press 4 To  Exit                    |"<<endl;
    cout<<"\n\t\t\t Please Enter Your Choice : ";
    cin>>choice;
    cout<<endl;

    switch (choice)
    {
    case 1:
        login();
        break;    
    
    case 2:
        registration();
        break;    
    
    case 3:
        forgot();
        break;    
    
    case 4:
        cout<<"\t\t\t THANKYOU FOR USING OUR SYSTEM\n\n\n";
        break; 
     
    default:
        system("cls");
        cout<<"\t\t\t PLEASE SELECT AN OPTION FROM ABOVE LIST!\n\n"<<endl; 
        main();       
    }

}

void login()
{
    int count;
    string userId, password, id, pass;
     system("cls");
     cout<<"\t\t\tEnter Username And Password"<<endl;
     cout<<"\t\t\tUSERNAME";
     cin>>userId;
     cout<<"\t\t\tPASSWORD";
     cin>>password;

     ifstream input("records.txt");    //input is the object.

     while(input>>id>>pass)
     {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");            
        }      
     }
     input.close();

     if(count==1)
     {
        cout<<userId<<"\nYour login Is successful\n Thanks For Logging in !";
        main();
     }
     else{
        cout<<"\nLOGIN ERROR\n Please Check Your Username !";
        main();
     }
}
void registration()
{
    string ruserId,rpassword, rid, rpass;
    system("cls");
     cout<<"\t\t\tEnter Username And Password"<<endl;
     cout<<"\t\t\tUSERNAME : ";
     cin>>ruserId;
     cout<<"\t\t\tPASSWORD : ";
     cin>>rpassword;

     ofstream f1("records.txt",ios::app);      //f1 is the object. ios is input output stream and app will open the file and append the output in the file.
     f1<<ruserId<<" "<<rpassword<<endl;
     system("cls");
     cout<<"\n\t\t\tRegistration Is Successfull !\n";
     main();   
}


void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t You Forgot The Password?\n";
    cout<<"Press 1 To Search Your Id By username."<<endl;
    cout<<"Press 2 To GO Back To The Main Menu."<<endl;
    cout<<"\t\t\tEnter Your Choice :";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count = 0;
            string fuserId, fId, fpass;
            cout<<"\n\t\t\tEnter The Username Which You Remembered : ";
            cin>>fuserId;
            ifstream f2("records.txt");
            while(f2>>fId>>fpass)
            {
                if(fId==fuserId)
                {
                    count = 1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n Your Account Is Found !\n";
                cout<<"\n\n Your Password Is :"<<fpass;
                main();
            }
            else{
                cout<<"\n\tSorry ! Your Account Is not Found.\n";
                main();
            }
            break;
        }
        case 2:
        {
            main();
        }
        default:
        cout<<"\t\t\t Wrong Choice ! Please Try Again."<<endl;
        forgot();
    }
}