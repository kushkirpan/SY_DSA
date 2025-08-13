#include<iostream>
using namespace std;

struct node{
  string songname;
  node* next;
};

class LL{
  private:
  node* head;
  public:
  LL(){
    head=NULL;
  }
  
  void addnode_begining(string songname){
    node *newnode = new node;
    newnode->songname=songname;
    if(head!=NULL){
      newnode->next=head;
      head=newnode;
    }
    else{
      newnode->next=NULL;
      head=newnode;
    }
  }
  
  void addnode_end(string songname){
    node *newnode = new node;
    newnode->songname=songname;
    newnode->next=NULL;
    if(head==NULL){
      head=newnode;
    }
    else{
      node* ptr=head;
      while(ptr->next!=NULL){
        ptr=ptr->next;
      }
      ptr->next=newnode;
    }
  }
  
  void addnode_position(string songname,int position){
    node *newnode = new node;
    newnode->songname=songname;
    node* ptr=head;
    int count=1;
    while(ptr->next!=NULL){
      count++;
      ptr=ptr->next;
    }
    cout<<"Count="<<count<<endl;
    if(head==NULL || position>=count+1){
      if(head==NULL){
        cout<<"The Playlist is empty so adding the song at 1st position."<<endl;
        newnode->next=NULL;
        head=newnode;
      }
      if(position>=count+1){
        cout<<"The position you Entered is "<<position<<"but the last position is "<<count<<"so adding the song at position"<<count+1<<"."<<endl;
        ptr=head;
        while(ptr->next!=NULL){
          ptr=ptr->next;
        }
        ptr->next=newnode;
      }
    }
    else if(position>0 && position<count+1){
      node* ptr1=head;
      node* ptr2=head;
      int i=1;
      while(i<position){
        i++;
        ptr2=ptr1;
        ptr1=ptr1->next;
      }
      newnode->next=ptr1;
      ptr2->next=newnode;
    }
  }
  
  void display(){
    cout<<endl;
    node* ptr=head;
    int count=0;
    if(head==NULL){
      cout<<"The Playlist is empty."<<endl;
    }
    else{ cout<<"Displaying Playlist : "<<endl;
    while(ptr!=NULL){
      count++;
      cout<<count<<" "<<ptr->songname<<endl;
      ptr=ptr->next;
    }
   }
    //cout<<"Count="<<count<<endl;
    //cout<<"Head="<<head->songname<<endl;
    cout<<endl;
  }
  
  string remove_begining(){
   if(head!=NULL){
    string song;
    node *ptr=head;
    head=head->next;
    song=ptr->songname;
    delete(ptr);
    return song;
   }
   else cout<<"The List is empty."<<endl;
   return "";
  }
  
  string remove_end(){
   if(head==NULL){
     cout<<"The List is empty."<<endl;
     return "";
    }
   else{ 
      string song;
      node* ptr=head;
      node* ptr2=head;
      while(ptr->next!=NULL){
        ptr2=ptr;
        ptr=ptr->next;
      }
      ptr2->next=NULL;
      song=ptr->songname;
      delete(ptr);
      return song;
    } 
  }
  
  string remove_position(int position){
   if(head==NULL){
     cout<<"The List is empty."<<endl;
     return "";
    }
   else{
    node* ptr=head;
    int count;
    for(count=0;ptr!=NULL;count++){
      ptr=ptr->next;
    }
    if(position>count){
      cout<<"List index out of bound."<<endl;
      return "";
    }
    else if(position<0){
      cout<<"Please Enter valid index."<<endl;
      return "";
    }
    else{
      position=position-1;
      node* ptr=head;
      node* ptr2=head;
      int i=0;
      while(i<position){
        ptr2=ptr;
        ptr=ptr->next;
        i++;
      }
      ptr2->next=ptr->next;
      string song=ptr->songname;
      delete(ptr);
      return song;
    }
   }
  }
  
  void play(string song){
    node* ptr=head;
    if(head==NULL){
      cout<<"The Playlist is empty."<<endl;
      return;
    }
    else{
    int s=0;
    while(ptr->next!=NULL){
      if(ptr->songname==song) {s=1;break;}
      ptr=ptr->next;
    }
    if(s==1){
      cout<<song<<" is playing."<<endl;
    }
    else if(s==0) cout<<"Song not present in Playlist."<<endl;
  }
  }
};


int main(){
  LL list1;
  int opt;
  string song;
  char subopt;
  do{
  cout<<"1. Add Song."<<endl;
  cout<<"2. Remove Song."<<endl;
  cout<<"3. Display Playlist."<<endl;
  cout<<"4. Play Specific Song."<<endl;
  cout<<"5. Exit."<<endl;
  cout<<endl;
  cout<<"Enter Option Number : ";
  cin>>opt;
    switch (opt) {
    case 1:
      cout<<"1. Add Song : "<<endl;
      cout<<"  a. Add at begining."<<endl;
      cout<<"  b. Add at end."<<endl;
      cout<<"  c. Add at position."<<endl;
      cout<<"Enter sub-option : ";
      cin>>subopt;
      cout<<"Enter Song Name : ";
      cin>>song;
      switch (subopt) {          
        case 'a':
          list1.addnode_begining(song);
          break;
        case 'b':
          list1.addnode_end(song);
          break;
        case 'c':
          int pos;
          cout<<"Enter Song Postion to Add : ";
          cin>>pos;
          list1.addnode_position(song,pos);
          break;
        default:
          cout<<"Enter correct option.";
          break;
      }
    break;
    case 2:
      cout<<"2. Remove Song : "<<endl;
      cout<<"  a. Remove at begining."<<endl;
      cout<<"  b. Remove at end."<<endl;
      cout<<"  c. Remove at position."<<endl;
      cout<<"Enter sub-option : ";
      cin>>subopt;
      switch (subopt) {
        case 'a':
          song=list1.remove_begining();
          cout<<song<<" Removed."<<endl;
          break;
        case 'b':
          song=list1.remove_end();
          cout<<song<<" Removed."<<endl;
          break;
        case 'c':
          int pos;
          cout<<"Enter Song Postion to Remove : ";
          cin>>pos;
          song=list1.remove_position(pos);
          cout<<song<<" Removed."<<endl;
          break;
        default:
          cout<<"Enter correct option.";
          break;
      }
    break;
    case 3:
      list1.display();
    break;
    case 4:
      cout<<"Enter Song you want to Play : ";
      cin>>song; 
      list1.play(song);
    break;
    case 5:
      cout<<"Thank You :)"<<endl;
      cout<<"Program Executed Successfully !"<<endl;
      break;
    default:
      cout<<"Enter correct option."<<endl;
      break;
    }
    cout<<endl;
  }while(opt!=5);
  
  return 0;
}