//Write a program in C++ to find the sum of an array (size 5) such that the
//sum is equal to the sum of all the elements of arr[] except arr[i]. You
//need to take the array elements as input from the users.
//*** Array can have zero and negative numbers
//Sample Input:
//The given array is: 1 2 3 4 5
//Sample Output :
//The sum array is: 14 13 12 11 10


#include<iostream>
using namespace std;
 
void sum(int a[],int n){
    int s=0;
    for(int i=0;i<n;i++){
        s=s+a[i];
    }
    //cout<<s;
    for(int i=0;i<n;i++){
        a[i]=s-a[i];
    }
}

void input(int a[],int n){
    cout<<"Enter Array Elements : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
 
int main(){
    int n;
    cout<<"Enter Number of elements : ";
    cin>>n;
    int a[n];
    input(a,n);
    cout<<"Input  : ";display(a,n);cout<<endl;
    sum(a,n);
    cout<<"Output : ";display(a,n);cout<<endl;
    return 0;
}
