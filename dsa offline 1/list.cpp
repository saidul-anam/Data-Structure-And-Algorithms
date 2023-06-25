#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    node *next;
    node(){
    next=NULL;
    }
    node(int a,node *next){
    value=a;
   this->next=next;
    }
};
class linklist{
node *head;
int length,cur;
public:

    void init(){
    head=NULL;
    length=0;
    cur=0;
    }
    linklist(){
    init();
    }
    ~linklist(){
  while(length>0){
    Remove();
  }
    }
    void Insert(int a){

    if(length==0){
                node *new_node=new node(a,NULL);
        head=new_node;
      cur=1;
    }
    else if(cur==1){
        node *new_node=new node(a,NULL);
     new_node->next=head;
        head=new_node;
    }
    else if(cur==length){
        node *new_node=new node(a,NULL);
        node *temp=head;
        while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=new_node;
    }
    else{
node *new_node=new node(a,NULL);
node*temp=head;
int a=cur;
while(a!=1){
    temp=head;
    temp=head->next;
    a--;
}
new_node->next=temp->next ;
temp->next=new_node;
    }
    length++;
    }
int Remove(){
    int a;
if(length==0){
    return NULL;
}
 else if(length ==1){
        a=head->value;
    delete head;
head=NULL;

}
else if(cur==1){
     a=head->value;
        node *new_node=head;
     head=head->next;
    delete new_node;

}
else if(cur==length){
    node *temp=head;
   node *temp2=head;
   int x=cur;
   while(x!=1){
    temp2=temp;
    temp=temp->next;
    x--;
   }
   a=temp->value;
   temp2->next=NULL;
   delete temp;
   temp=NULL;
}
else{
    node *temp=head;
   int x=cur;
   node *temp2=head;
   while(x!=1){
   temp2=temp;
   temp=temp->next;
   }
   a=temp->value;
   temp2->next=temp->next;
   delete temp;
   temp=NULL;
}
length--;
return a;
}
void moveToStart(){
cur=1;}
void moveToEnd(){
cur=length;
}
void prev(){
if(length!=0&&cur>1){
    cur=cur-1;
}
}
void next(){
if(length!=0&&cur!=length){
    cur=cur+1;
}
}
int Length(){
return length;
}
int currPos(){
return cur;
}
void moveTopos(int pos){
cur=pos;
}
int getvalue(){
if(length==0||cur>length){
    return NULL;
}
int x=cur;
node *temp=head;
for(int i=1;i<cur;i++){
    temp=temp->next;
}
int z=temp->value;
return z;
}
 void print(){
 if(length==0){
    cout<<"<>"<<endl;
    return ;
 }
 else{
    cout<<"<";
        node *newnode=head;
        int z=cur;
        while (z!=1){
            cout<<newnode->value<<" ";
            newnode=newnode->next;
            z--;
        }
        cout<<"|";
        int k=cur;
        int m=length-1;
        while(m>=k){
                cout<<newnode->value<<" ";
        newnode=newnode->next;
        m--;
        }
        cout<<newnode->value<<">"<<endl;
 }
 }
 void Clear(){
 void moveToStart();
 int z=length;
 while(z!=0){
    int a=Remove();
    z--;
 }
 }
int Search(int a){
    int m=cur;
    moveToStart();
    node *temp=head;
    int i;
    for(i=1;i<=length;i++){
        int k=getvalue();
        if(k==a){
            break;
        }
        moveTopos(i+1);
    }
moveTopos(m);
if(i<=length){
    return i;
}
else{
    return NULL;
}
}
void Append(int a){
    int k=cur;
moveToEnd();
Insert(a);
cur=k;

}
};
