#include<iostream>


using namespace std;

int a[100],size;


void linearSearch(int key){
    int flag=-1;

    for (int i = 0; i < size; i++){
       if (key==a[i])
       {
        flag=i;
        break;
       }
       
    }

    if (flag!=-1){
        cout<<key<<" was present for the programme.\n";
    }
    else{
        cout<<key<<" was absent for the programme.\n";
    }
    
}

void binarySearch(int key){
    int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if (a[i]>a[j]){

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                }
            }
            
        }

        int low = 0;
        int high = size-1;
        int mid = (low + high)/2;

        while (low<=high)
        {
            if (a[mid]==key)
            {
            cout<<key<<" was present for the programme.\n";
            break;
            }
            else if (key>a[mid])
            {
                 low = mid+1;
            }
            else{
                high = mid - 1;
            }
        mid = (low + high)/2;             
        }
        
    if (low>high)
    {
        cout<<key<<" was absent for the programme.\n";
    }
    
        
}
int main(){
    int key,ch;

    cout<<"Enter the no. of students: ";
    cin>>size;

    cout<<"Enter the roll numbers\n";

    for (int i = 0; i < size; i++){
    cout<<"Enter the roll number for student "<<i+1<<": ";
    cin>>a[i];
    }

    do{
    
    cout<<"Enter the roll no for search: ";
    cin>>key;

    cout<<"1-linearSearch  2-BinarySearch 0-exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;

    switch (ch){
    case 1:
        linearSearch(key);
        break;
    case 2:
        binarySearch(key);
        break;
    }

    } while (ch!=0);
}
