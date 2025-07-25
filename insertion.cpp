#include<iostream>
using namespace std;

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
    cout<<"Sorted Array : ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
   int a[9]={2,5,1,8,9,3,4,11,6};
   insertion(a,9);
   return 0;
}