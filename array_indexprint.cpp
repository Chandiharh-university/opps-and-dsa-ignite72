

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number of elements you want to write : "<<endl;
    cin>>n;
    
    cout<<"Enter Elements : ";
    int arr[n];
    
    for(int i=3;i<n;i++){
        cin>>arr[i];
    }
    
    //cout<<"For checking : "<<endl;
    //cout<<arr[0];
    //cout<<arr[1];
    //cout<<arr[2];
    
    
    cout<<"Entered Elements are : ";
    for(int i=3;i<n;i++){
        cout<<arr[i];
        cout<<endl;
    }
    

    return 0;
}
