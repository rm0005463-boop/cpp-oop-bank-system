#include <iostream>
#include"clsBankClient.h";

using namespace std;

int main()
{
    
    clsBankClient Client1 = clsBankClient::Find("A150");
    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("A150" , "1222");
    Client2.Print();

    system("pause>0");
    return 0;
}