#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class MENU
{
    int choice;
    public:
    void print();
    int scan();
};

class USER_REG
{
    int comp;
    string username, password, userid, pass;
    public:
    void r_userinfo();
    void write_in_file();
    int check_duplicate();
};

class LOGIN
{
    int comp;
    string username, password, userid , pass;
    public:
    void r_username();
    void r_password();
    void check_username();
    void check_password();
};

class F_PASS
{
    int comp;
    string username, userid, password;
    public:
    void forget();
};

