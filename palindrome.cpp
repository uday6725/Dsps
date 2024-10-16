#include<iostream>
#include<string>
using namespace std;
string a[50],b[50];
int top=-1,i=0,flag=0;
void push(string n,int num)
{
    if(top<num){
        top++;
        a[top]=n;
    }
    else{
        cout<<"stackoverflow"<<endl;
    }
    }

void reverse()
{
    if(top==-1)
    {
        cout<<"stack empty"<<endl;
    }
    else{
        b[i]=a[top];
        top--;
        i++;
    }
}
bool isPalindrome(){
    if(i<50){
        if(a[i]==b[i]){
            i++;
            isPalindrome();
            return true;
        }
        else{
            return false;
        }
    }
}
int main()
{
    int num;
    cout<<"enter the no of elements in the string";
    cin>>num;
    for(int j=0;j<num;j++){
        cin>>a[j];
        push(a[j],num);
    }
    for(int j=0;j<num;j++)
    {
        reverse();
    }
    i=0;
    isPalindrome();
    if(isPalindrome()){
        cout<<"string is palindrome";

    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}
