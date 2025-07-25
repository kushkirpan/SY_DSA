#include<iostream>
using namespace std;
 
struct student{
    int age;
    string name;
    int prn; 
} 
 
int main(){
    int n;
    cout<<"Enter number of student : ";
    cin>>n;
    student s[n];
    cout<<"Enter Student data."<<endl;
    for(int i=0;i<n;++i){
        cout<<"Student "<<i<<" : "<<endl;
        cout<<"Enter Name : ";
        cin>>s[i].name;
        cout<<"Enter Age  : ";
        cin>>s[i].age;
        cout<<"Enter PRN  : ";
        cin>>s[i].prn;
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        
    }
    return 0;
}