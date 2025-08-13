#include<iostream>
#include<iostream>
using namespace std;
 

 
int main(){
    int n=6;
    char org[n]="balaji";
    char cyc[n]="lajiba";
    char temp[n];
    int index[n];
    int count=0;
    int test[n];
    for(int i=0;i<n;i++){
        if(org[0]==cyc[i]){
            index[count]=i;
            count++;
        }
    }
    int k=1;
while(k<=count){
    int i=0;
    int j=index[k];
    while(j<n && j>=index[k]){
        temp[i]=cyc[j];
        j++;
        i++;
    }
    j=0;
    do{
        temp[i]=cyc[j];
        j++;
        i++;
    }while(j>=0 && j<index[k]);
    int s=1;
    for(int i=0;i<n;i++){
        if(org[i]==temp[i]){}
        else {s=0;break;}
    }
    if(s==1){
        test[k]=1;
    }
    else{
        test[k]=0;
    }
    k++;
}
    int sum=0;
    for(int i=1;i<=count;i++){
        sum=test[i]+sum;
    }
    if(sum==0){
        cout<<"False"<<endl;
    }
    else cout<<"True"<<endl;
    cout<<temp<<endl;
    return 0;
}