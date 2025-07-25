#include<iostream>
using namespace std;

struct student{
  int roll_no;
  string name;
  float cgpa;
};

void accept(student s[],int n){
  //student s[n];
  for(int i=0;i<n;i++){
    cout<<"Enter Data for Student "<<i+1<<" : "<<endl;
    cout<<"Enter Roll No. : ";
    cin>>s[i].roll_no;
    //cout<<"hello";
    cout<<"Enter Name     : ";
    cin>>s[i].name;
    cout<<"Enter CGPA     : ";
    cin>>s[i].cgpa;
  }
}

void display(student s[],int n){ 
  cout<<"Roll No."<<"  Name  "<<"CGPA"<<endl;
  for(int i=0;i<n;i++){
    cout<<s[i].roll_no<<"      "<<"  "<<s[i].name<<"  "<<" "<<s[i].cgpa<<" "<<endl;
  }
}

void insertion(student s[],int n){
  for(int i=1;i<n;i++){
    student key=s[i];
    int j=i-1;
    while(j>=0 && s[j].roll_no > key.roll_no){
      s[j+1]=s[j];
      j--;
    }
    s[j+1]=key;
  }
}

int opt(){
  cout<<"1. Accept Record."<<endl;
  cout<<"2. Display Record."<<endl;
  cout<<"3. Sort on Roll No. (Insertion Sort)."<<endl;
  cout<<"4. Exit."<<endl;
  int option;
  cout<<"Enter Choice : ";
  cin>>option;
  return option;
}

int main(){
  int x;
  cout<<"Enter No. of Students : ";
  cin>>x;
  student std[x];
  int choice=opt();
  int ok=1;
  do{
    switch (choice){
    case 1:
      accept(std,x);
      choice=opt();
      break;
    case 2:
      display(std,x);
      choice=opt();
      break;
    case 3:
      insertion(std,x);
      choice=opt();
      break;
    case 4:
      cout<<"Thank You :)"<<endl;
      cout<<"Program Executed Successfully !"<<endl;
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
