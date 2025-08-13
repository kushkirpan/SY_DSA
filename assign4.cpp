#include<iostream>
using namespace std;

struct node{
  node *prev;
  char text;
  node *next; 
};

class DLL{
  node *head; 
  node *tail;
  public:
  DLL(){
    head=NULL;
    tail=NULL;
  }
  void display(){
    node *ptr=head;
    while(ptr!=NULL){ //OR while(ptr!=tail->next)
      cout<<ptr->text;
      ptr=ptr->next;
    }
  }
  
  void insert_start(char data){
    node *newnode = new node;
    newnode->text=data;
    if(head==NULL){
      newnode->prev=NULL;
      newnode->next=NULL;
      head=newnode;
      tail=newnode;
    }
    else{
      newnode->prev=NULL;
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
    }
   }
   
   void insert_end(char data){
    node *newnode = new node;
    newnode->text=data;
    if(head==NULL){
      newnode->prev=NULL;
      newnode->next=NULL;
      head=newnode;
      tail=newnode;
    }
    else{
      newnode->prev=tail;
      newnode->next=NULL;
      tail->next=newnode;
      tail=newnode;
    }
  }
  
  void insert_position(DLL obj,char data,int pos){
    node *newnode = new node;
    newnode->text=data;
    node *ptr=head;
    int count=0;
    while(ptr!=NULL){
      count++;
      ptr=ptr->next;
    }
    if(head==NULL){
      newnode->prev=NULL;
      newnode->next=NULL;
      head=newnode;
      tail=newnode;
    }
    else if(pos>0 && pos<=count){
      node *ptr2=head;
      ptr=head;
      for(int i=1;i<pos;i++){
        ptr2=ptr;
        ptr=ptr->next;
      }
      newnode->prev=ptr2;
      newnode->next=ptr;
      ptr2->next=newnode;
      ptr->prev=newnode;
    }
    else if(pos==count+1){
      newnode->prev=tail;
      newnode->next=NULL;
      tail->next=newnode;
      tail=newnode;
    }
    else{
      cout<<"Position out of bound."<<endl;
    }
  }
  
  char delete_start(){
    char rt=' ';
    if(head==NULL){
      cout<<"Text Editor is Empty."<<endl;
    }
    else{
      node *ptr=head;
      head->next->prev=NULL;
      head=head->next;
      rt=ptr->text;
      delete(ptr);
    }
    return rt;
  }
  
  char delete_end(){
    char rt=' ';
    if(head==NULL){
      cout<<"Text Editor is Empty."<<endl;
    }
    else{
      node *ptr=tail;
      tail->prev->next=NULL;
      tail=tail->prev;
      rt=ptr->text;
      delete(ptr);
    }
    return rt;
  }

  char delete_position(int pos){
    node *ptr=head;
    int count=0;
    char rt=' ';
    while(ptr!=NULL){
      count++;
      ptr=ptr->next;
    }
    if(head==NULL){
      cout<<"Text Editor is Empty."<<endl;
    }
    else if(pos>0 && pos<count){
      node *ptr2=head;
      ptr=head;
      for(int i=1;i<pos;i++){
        ptr2=ptr;
        ptr=ptr->next;
      }
      ptr->next->prev=ptr->prev;
      ptr->prev->next=ptr->next;
      rt=ptr->text;
      delete(ptr);
    }
    else if(pos==count){
      ptr=tail;
      tail->prev->next=NULL;
      tail=tail->prev;
      rt=ptr->text;
      delete(ptr);
    }
    else{
      cout<<"Position out of bound."<<endl;
    }
    return rt;
  }

  void search(char text){
    node *ptr=head;
    int pos=0,swt=0;
    while(ptr!=NULL){
      if(ptr->text==text){
        swt=1;
        pos++;
        break;
      }
      ptr=ptr->next;
      pos++;
    }
    if(swt==1){
      cout<<"Char found at position : "<<pos<<endl;
    }
    else{
      cout<<"Char NOT found."<<endl;
    }
  }

  void reverse(){
    cout<<endl;
    node *ptr=tail;
    while(ptr!=NULL){
      cout<<ptr->text;
      ptr=ptr->prev;
    }
    cout<<endl;
  }

};

//kusrsrsrsrsrsr

int main(){
  DLL txt;
  int opt;
  char text;
  char subopt;
  do{
  cout<<"1. Insert Char."<<endl;
  cout<<"2. Delete Char."<<endl;
  cout<<"3. Display Text."<<endl;
  cout<<"4. Search."<<endl;
  cout<<"5. Print in Reverse."<<endl;
  cout<<"6. Exit."<<endl;
  cout<<endl;
  cout<<"Enter Option Number : ";
  cin>>opt;
    switch (opt) {
    case 1:
      cout<<"1. Insert Char : "<<endl;
      cout<<"  a. Insert at begining."<<endl;
      cout<<"  b. Insert at end."<<endl;
      cout<<"  c. Insert at position."<<endl;
      cout<<"Enter sub-option : ";
      cin>>subopt;
      cout<<"Enter Char : ";
      cin>>text;
      switch (subopt) {          
        case 'a':
          txt.insert_start(text);
          break;
        case 'b':
          txt.insert_end(text);
          break;
        case 'c':
          int pos;
          cout<<"Enter  Postion to Add : ";
          cin>>pos;
          txt.insert_position(txt,text,pos);
          break;
        default:
          cout<<"Enter correct option.";
          break;
      }
    break;
    case 2:
      cout<<"2. Delete Char : "<<endl;
      cout<<"  a. Delete at begining."<<endl;
      cout<<"  b. Delete at end."<<endl;
      cout<<"  c. Delete at position."<<endl;
      cout<<"Enter sub-option : ";
      cin>>subopt;
      switch (subopt) {
        case 'a':
          cout<<txt.delete_start()<<" Deleted."<<endl;
          break;
        case 'b':
          cout<<txt.delete_end()<<" Deleted."<<endl;
          break;
        case 'c':
          int pos;
          cout<<"Enter Char Postion to Delete : ";
          cin>>pos;
          cout<<txt.delete_position(pos)<<" Deleted."<<endl;
          break;
        default:
          cout<<"Enter correct option.";
          break;
      }
    break;
    case 3:
      cout<<endl;
      cout<<"Entered Text : ";
      txt.display();
      cout<<endl;
    break;
    case 4:
      cout<<"Enter the Char you want to Search : ";
      cin>>text; 
      txt.search(text);
    break;
    case 5:
      cout<<"Reverse : "; 
      txt.reverse();
    break;
    case 6:
      cout<<"Thank You :)"<<endl;
      cout<<"Program Executed Successfully !"<<endl;
      break;
    default:
      cout<<"Enter correct option."<<endl;
      break;
    }
    cout<<endl;
  }while(opt!=6);
  
  return 0;
}