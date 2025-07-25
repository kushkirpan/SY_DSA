#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int temp=*b;
    *b=*a;
    *a=temp;    
}
 
void shell(int a[],int n){
    int gap=n/2;
    while(gap>=1){
        int j=gap;
        while(j<=n-1){
            int i=j-gap;
            while(i>=0){
                if(a[i]<a[i+gap]){
                    break;
                }
                else{
                    swap(a[i],a[i+gap]);
                }
                i=i-gap;
            }
            ++j;
        }
        gap=gap/2;
    }
}
 
int main(){
    int arr[]={7,5,6,8,1,9,3,2,4};
    shell(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    return 0;
}