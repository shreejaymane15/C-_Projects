#include"login.h"


int main()
{
    int choice = 1;
    while(choice)
    {
        MENU m;
        m.print();
        choice  = m.scan();
        switch(choice)
        {
            case 1:
                {
                    USER_REG U;
                    U.r_userinfo();
                    cout<<"\t\t\tRegistration Complete."<<endl<<"\t\t\t";
                    system("pause");
                }
                break;
            case 2:
                {
                    LOGIN L;
                    L.r_username();
                    L.r_password();
                    system("pause");
                }
                break;
            case 3:
                {
                    F_PASS F;
                    F.forget();
                }
        }           
    }
}
