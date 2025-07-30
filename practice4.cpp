#include<iostream>
using namespace std;

struct employee{
  string name;
  int epid;
  float salary;
};

void accept(employee* a[],int n){
  for(int i=0;i<n;i++){
    a[i] = new employee;
    cout<<"Enter Data for Employee "<<i+1<<" : "<<endl;
    cout<<"Enter Employee Id : ";
    cin>>a[i]->epid;
    cout<<"Enter Name     : ";
    cin>>a[i]->name;
    cout<<"Enter Salary     : ";
    cin>>a[i]->salary;
    cout<<endl;
  }
}

void display(employee* a[],int n){ 
  cout<<"Employee Id"<<"  Name  "<<"Salary"<<endl;
  for(int i=0;i<n;i++){
    cout<<a[i]->epid<<"      "<<"  "<<a[i]->name<<"  "<<" "<<a[i]->salary<<" "<<endl;
  }
  cout<<endl;
}

int opt(){
  cout<<"1. Accept Record."<<endl;
  cout<<"2. Display Record."<<endl;
  cout<<"3. Find Max Salary Employee."<<endl;
  cout<<"4. Exit."<<endl;
  cout<<endl;
  int option;
  cout<<"Enter Choice : ";
  cin>>option;
  cout<<endl;	
  return option;
}

int max(employee *a[],int n){
  float max=a[0]->salary;
  int max_index=0;
  for(int i=0;i<n;i++){
    if(a[i]->salary>max){
      max=a[i]->salary;
      max_index=i;
    }
  }
  return max_index;
}



int main(){
  int x;
  cout<<endl;
  cout<<"Enter No. of Employees : ";
  cin>>x;
  employee* e[x];
  cout<<endl;
  int choice=opt();
  int ok=1;
  int n;
  do{
    switch (choice){
    case 1:
      accept(e,x);
      choice=opt();
      break;
    case 2:
      display(e,x);
      choice=opt();
      break;
    case 3:
      n=max(e,x);
      cout<<"Highest Salaried Employee : "<<endl;
      cout<<"Employee ID   : "<<e[n]->epid<<endl;
      cout<<"Employee Name : "<<e[n]->name<<endl;
      cout<<"Salary        : "<<e[n]->salary<<endl;
      choice=opt();
      break;
    case 4:
      cout<<"Thank You :)"<<endl;
      cout<<"Program Executed Successfully !"<<endl;
      cout<<endl;
      ok=0;
      break;
    default:
      cout<<"Please Enter Correct Choice !"<<endl;
      choice=opt();
      break;
  }
  }while(ok==1);
  return 0;
}
