#include<iostream>
using namespace std;
 
void fun(int a[5][4]){
    int ilb=0,jlb=0,m=5,n=4,i,j,iub=5-1,jub=4-1;
    do{
        i=ilb;
        j=jlb;
        while(j<=jub){
            cout<<a[i][j]<<" ";
            j++;
        }
        ilb++;
        j=jub;
        i=ilb;
        while(i<=iub){
            cout<<a[i][j]<<" ";
            i++;
        }
        jub--;
        i=iub;
        j=jub;
        while(j>=jlb){
            cout<<a[i][j]<<" ";
            j--;
        }
        iub--;
        j=jlb;
        i=iub;
        while(i>=ilb){
            cout<<a[i][j]<<" ";
            i--;
        }
        jlb++;
    }while(i<=m && j<=n);
    cout<<endl;
}

void accept_array(int a[5][4]){
    int m=5,n=4;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}

void display_array(int a[5][4]){
    int m=5,n=4;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
int main(){
    int arr[5][4];
    cout<<"Enter Numbers : ";
    accept_array(arr);
    cout<<endl;
    cout<<"Entered Matrix : "<<endl;
    display_array(arr);
    cout<<endl;
    cout<<"Spiral Pattern : ";
    fun(arr);
    cout<<endl;
    return 0;
}