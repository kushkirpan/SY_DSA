#include<iostream>
using namespace std;
 
int b[100];
void merge(int a[],int lb,int mid,int ub){
    int i=lb;
    int k=lb;
    int j=mid+1;
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
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

void mergesort(int a[],int lb,int ub){
    if(lb<ub){
        int mid=(ub+lb)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
 
int main(){
    int arr[]={170,45,75,90,802,24,2,66};
    mergesort(arr,0,7);
    for(int i=0;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}