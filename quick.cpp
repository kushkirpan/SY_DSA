#include<iostream>
using namespace std;
 
int partition(int a[],int lb, int ub){
    int pivot=a[lb];
    int p=lb;
    int q=ub;
    while(lb<ub){
        while(a[lb]<=pivot){
            lb++;
        }
        while(pivot<a[ub]){
            ub--;
        }
        if(lb<ub){
            swap(a[lb],a[ub]);
        }
    }
    swap(a[p],a[ub]);
    return ub;
}

void quicksort(int a[],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
 
int main(){
    int arr[]={170,45,75,90,802,24,2,66};
    quicksort(arr,0,7);
    for(int i=0;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}