#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=b;
    b=a;
    a=temp;    
}
 
void shell(int a[],int n){
    for(int gap=n/2;gap>=1;gap=gap/2){
        for(int j=gap;j<=n-1;++j){
            for(int i=j-gap;i>=0;i=i-gap){
                if(a[i]<a[i+gap]){
                    break;
                }
                else{
                    swap(a[i],a[i+gap]);
                }
            }
        }
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