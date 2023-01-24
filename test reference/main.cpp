#include<iostream>
#include<fstream>
#include<string>

using namespace std;
bool IsLoggedIn()
{
    string username, password, un, pw;   //un and pw are for comparing.
    cout << "Enter Your Username: ";
    cin >> username;
    cout << "enter Your Secret Pin: ";
    cin >> password;

    ifstream read("c:\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;
    cout << "1: Register\n2: Login\n3: Your Choice: ";
    cin>>choice;
    if(choice == 1)
    {
        string username, password;
        cout << "Select A Username: ";
        cin >> username;
        cout << "Select A Secret PIN: ";
        cin >> password;
  
        fstream cases;
        
        cases.open("c:\\" + username + ".txt");
        cases << username << endl<< password;
        cases.close();
        main();
    }
    else if(choice == 2)
    {
        bool status = IsLoggedIn();

        if(!status)
        {
            cout << "False Login!!!"<<endl;
            system("PAUSE");
            return 0;   //for false condition.
        }
        else{
            cout << "Successfully Logged In!!!"<<endl;
             system("PAUSE");
             return 1;   //for true condition.
        }
    }
}