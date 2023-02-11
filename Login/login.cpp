#include"login.h"
using namespace std;

void MENU::print()
{
    system("cls");
    cout<<"************************************!!!!!Welcome To Shree Security!!!!!************************************"<<endl<<endl;
    cout<<"____________________________________------------User Manual------------____________________________________"<<endl<<endl;
    cout<<"\t\t\tPress 1. User Registration"<<endl;
    cout<<"\t\t\tPress 2. Login"<<endl;
    cout<<"\t\t\tPress 3. Forget Password"<<endl;
    cout<<"\t\t\tPress 0. Exit"<<endl;
}

int MENU::scan()
{
    cout<<endl<<"\t\t\tEnter Choice: ";
    cin>>MENU::choice;
    if(MENU::choice > 3 || MENU::choice < 0)
    {
        cout<<"\t\t\tWrong Choice"<<endl;
        cout<<"\t\t\t**WARNING : Choose Between Above Options**"<<endl<<"\t\t\t";
        system("pause");
        MENU::scan();
    }
    else
        return MENU::choice;
}

void USER_REG::r_userinfo()
{
    system("cls");
    cout<<"************************************!!!!!Welcome To Shree Security!!!!!************************************"<<endl<<endl;
    cout<<"____________________________________----------User Registration--------____________________________________"<<endl<<endl;
    cout<<"\t\t\tUsername: ";
    cin>>USER_REG::username;
    if(USER_REG::check_duplicate())
    {
        cout<<"\t\t\tPassword: ";
        cin>>USER_REG::password;
        USER_REG::write_in_file();
    }
}

void USER_REG::write_in_file()
{
    ofstream outfile("Login.txt", ios::app);
    outfile<<USER_REG::username<<endl<<USER_REG::password<<endl;
    outfile.close();
}

int USER_REG::check_duplicate()
{
    ifstream infile("Login.txt");
    while(infile>>USER_REG::userid>>USER_REG::pass)
    {
        if(username == userid)
        {
            USER_REG::comp = 0;
            break;
        }
        else
            USER_REG::comp = 1;
    }
    infile.close();
    if(USER_REG::comp == 0)
    {
        cout<<endl<<"\t\t\tUser Already Exist"<<endl;
        system("pause");
        USER_REG::r_userinfo();
    }
    else
    {
        return USER_REG::comp;
    }
}

void LOGIN::r_username()
{
    system("cls");
    cout<<"************************************!!!!!Welcome To Shree Security!!!!!************************************"<<endl<<endl;
    cout<<"____________________________________------------User Login------------____________________________________"<<endl<<endl;
    cout<<"\t\t\tUsername: ";
    cin>>LOGIN::username;
    LOGIN::check_username();
}

void LOGIN::r_password()
{
    cout<<"\t\t\tPassword: ";
    cin>>LOGIN::password;
    LOGIN::check_password();
}

void LOGIN::check_username()
{
    ifstream infile("Login.txt");
    while(infile>>LOGIN::userid>>LOGIN::pass)
    {
        if(userid == username)
        {    
            LOGIN::comp = 1;
            break;
        }
        else
            LOGIN::comp = 0;
    }
    infile.close();
    if(LOGIN::comp == 0)
    {
        cout<<"\t\t\tUsername Invalid"<<endl<<"\t\t\t";
        system("pause");
        LOGIN::r_username();
    }
}

void LOGIN::check_password()
{
    if(password == pass)
    {
        cout<<"\t\t\tLogin Successfull"<<endl;
        cout<<"\n\n\t\t\t\tWelcome "<<LOGIN::username<<"!!!"<<endl<<"\t\t\t";
    }
    else
    {
        cout<<"\t\t\tPassword Invalid"<<endl<<"\t\t\t";
        system("pause");
        LOGIN::r_password();
    }
}

void F_PASS::forget()
{
    system("cls");
    cout<<"************************************!!!!!Welcome To Shree Security!!!!!************************************"<<endl<<endl;
    cout<<"____________________________________------------Forget Password------------____________________________________"<<endl<<endl;
    cout<<"\t\t\tUsername: ";
    cin>>F_PASS::username;
    ifstream infile("Login.txt");
    while(infile>>F_PASS::userid>>F_PASS::password)
    {
        if(userid == username)
            {    
            F_PASS::comp = 1;
            break;
        }
        else
            F_PASS::comp = 0;
    }
    infile.close();
    if(F_PASS::comp == 0)
    {
        cout<<"\t\t\tUsername Invalid"<<endl<<"\t\t\t";
        system("pause");
        F_PASS::forget();
    }
    else
    {
        cout<<"\t\t\tYour Password is "<<F_PASS::password<<endl<<"\t\t\t";
        system("pause");
    }
}