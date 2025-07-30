#include<iostream>
using namespace std;
 
int c[100];

bool search(int a[],int ub,int t){
    int temp=0;
    for(int i=0;i<=ub;i++){
        if(a[i]==t){
            return true;
            temp=1;
            break;
        }
    }
    if(temp=0)return false;
}

void insertion(int arr[],int n){
    for(int i=1;i<n;++i){
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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

int Union(int a[],int n,int b[],int m){
    if(n<m){
        for(int i=0;i<m;i++){
            c[i]=b[i];
        }
        int s=m;
        for(int i=0;i<n;i++){
            if(!search(c,s,a[i])){
                c[s]=a[i];
                s++;
            }
        }
        insertion(c,s);
        return s;
    }
    
    else{
        for(int i=0;i<n;i++){
            c[i]=a[i];
        }
        int s=n;
        for(int i=0;i<m;i++){
            if(!search(c,s,b[i])){
                c[s]=b[i];
                s++;
            }
        }
        insertion(c,s);
        return s;
    }
}

int Intersection(int a[],int n,int b[],int m){
    int s=0;
    for (int i=0;i<m;i++){
        if(search(a,n-1,b[i])){
            c[s]=b[i];
            s++;
        }
    }
    insertion(c,s);
    return s;
}
 
int main(){
    cout<<"Enter Size of 1st Array : ";
    int p;
    cin>>p;
    int a[p];
    input(a,p);
    cout<<"Enter Size of 2nd Array : ";
    int q;
    cin>>q;
    int b[q];
    input(b,q);
    cout<<"Array 1 : ";
    display(a,p);
    cout<<endl;
    cout<<"Array 2 : ";
    display(b,q);
    cout<<endl;
    int n = Union(a,p,b,q);
    cout<<"Union : ";
    display(c,n);
    cout<<endl;
    n = Intersection(a,p,b,q);
    cout<<"Intersection : ";
    display(c,n);
    cout<<endl;
    return 0;
}