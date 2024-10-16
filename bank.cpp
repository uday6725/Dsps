#include<iostream>
#include<cstring>
using namespace std;
class Bank
{
    public:
    string dname;
    int accno;
    float amt;
    float bal=0.0;
    int dcount=0,wcount=0;
    void accept(string name,int acc,float b)
    {
        dname=name;
        accno=acc;
        bal=b;
        cout<<"data is accepted"<<endl;
    }
    void withdraw(float amount,float b)
    {   bal=b;
        amt=amount;
        if(amt>bal){
            cout<<"insufficient balance"<<endl;
        }
        else{
        bal-=amt;
        wcount++;
        }
    }
    void deposit(float amnt)
    {
        amt=amnt;
        bal+=amnt;
        dcount++;
    }
    void display()
    {
        cout<<"details"<<endl;
        cout<<"name"<<dname<<endl;
        cout<<"accno"<<accno<<endl;
        cout<<"balance"<<bal<<endl;
        cout<<"deposit count"<<dcount<<endl;
        cout<<"withdraw count"<<wcount<<endl;
    }
};
int main()
{
    Bank bank;
    string name;
    int acc,ch;
    float b;
    float amount,amnt;
    char c;
    cout<<"enter details"<<endl;
    cout<<"name of depositor"<<endl;
    cin>>name;
    cout<<"enter the acc no"<<endl;
    cin>>acc;
    cout<<"enter the bank balance"<<endl;
    cin>>b;
    bank.accept(name,acc,b);
    do{
    cout<<"enter whatyou want to do \1.deposit \n2.withdraw \n3.view balance"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
        cout<<"enter the amount to deposit"<<endl;
        cin>>amnt;
        bank.deposit(amnt);
        break;

        case 2:
        cout<<"enter the amount to withdraw"<<endl;
        cin>>amount;
        bank.withdraw(amount,b);
        break;

        case 3:
        bank.display();
        break;

        default:
        exit(0);
        break;
    }
    cout<<"do you want to continue y/n"<<endl;
    cin>>c;
    }while(c=='y'||c=='Y');
    return 0;
}
