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
  cout<<"3. Sort on Employee Id (Quick Sort)."<<endl;
  cout<<"4. Sort on Name (Merge Sort)."<<endl;
  cout<<"5. Exit."<<endl;
  cout<<endl;
  int option;
  cout<<"Enter Choice : ";
  cin>>option;
  cout<<endl;	
  return option;
}

void merge(employee *a[],int lb,int mid,int ub,employee* b[]){
    int i=lb;
    int k=lb;
    int j=mid+1;
    while(i<=mid && j<=ub){
        if(a[i]->name<=a[j]->name){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=ub){
        b[k]=a[j];
        j++;
        k++;
    }
    for(int p=lb;p<=ub;p++){
        a[p]=b[p];
    }
}

void mergesort(employee* a[],int lb,int ub,employee* b[]){
    if(lb<ub){
        int mid=(ub+lb)/2;
        mergesort(a,lb,mid,b);
        mergesort(a,mid+1,ub,b);
        merge(a,lb,mid,ub,b);
    }
}

int partition(employee* a[],int lb, int ub){
    int pivot=a[lb]->epid;
    int p=lb;
    int q=ub;
    while(lb<ub){
        while(a[lb]->epid<=pivot){
            lb++;
        }
        while(pivot<a[ub]->epid){
            ub--;
        }
        if(lb<ub){
            swap(a[lb],a[ub]);
        }
    }
    swap(a[p],a[ub]);
    return ub;
}

void quicksort(employee* a[],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}

int main(){
  int x;
  cout<<endl;
  cout<<"Enter No. of Employees : ";
  cin>>x;
  employee* e[x];
  employee* b[x];
  cout<<endl;
  int choice=opt();
  int ok=1;
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
      quicksort(e,0,x-1);
      choice=opt();
      break;
    case 4:
      mergesort(e,0,x-1,b);
      choice=opt();
      break;
    case 5:
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
