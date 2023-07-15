#include"1_ll_queue.h"

template <class t>
    void linklist<t>::init(){
    head=NULL;
    length=0;
    cur=0;
    }
    template <class t>
   linklist<t>:: linklist(){
    init();
    }
    template <class t>
    linklist<t>::~linklist(){
  while(length>0){
    Remove();
  }

    }
    template <class t>
    void linklist<t>:: Insert(t a){

    if(length==0){
                node<t> *new_node=new node<t>(a,NULL);
        head=new_node;
    }
    /*else if(cur==1){
        node<t> *new_node=new node<t>(a,NULL);
     new_node->next=head;
        head=new_node;
    }*/
    else if(cur==length){
        node<t> *new_node=new node<t>(a,NULL);
        node<t> *temp=head;
        while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=new_node;
    }
    else{
node<t> *new_node=new node<t>(a,NULL);
node<t>*temp=head;
int a=cur;
while(a!=1){
   /// temp=head;
    temp=head->next;
    a--;
}
new_node->next=temp->next ;
temp->next=new_node;
    }
    length++;
    cur++;
    }
    template <class t>
t linklist<t>::  Remove(){
    t a;
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
        node<t> *new_node=head;
     head=head->next;
    delete new_node;

}
else if(cur==length){
    node<t> *temp=head;
   node<t> *temp2=head;
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
    node<t> *temp=head;
   int x=cur;
   node<t> *temp2=head;
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
template <class t>
void linklist<t>:: moveToStart(){
cur=1;}
template <class t>
void linklist<t>::moveToEnd(){
cur=length;
}
template <class t>
void linklist<t>::prev(){
if(length!=0&&cur>1){
    cur=cur-1;
}
}
template <class t>
void linklist<t>::next(){
if(length!=0&&cur!=length){
    cur=cur+1;
}
}
template <class t>
int linklist<t>::Length(){
return length;
}
template <class t>
int linklist<t>::currPos(){
return cur;
}
template <class t>
void linklist<t>::moveTopos(int pos){
cur=pos;
}
template <class t>
t linklist<t>::getvalue(){
if(length==0||cur>length){
    return 0;
}

int x=cur;
node<t> *temp=head;
for(int i=1;i<cur;i++){
    temp=temp->next;
}
t z=temp->value;
return z;
}
template <class t>
 void linklist<t>::print(){
 if(length==0){
    cout<<"<>"<<endl;
    return ;
 }
 else{
    cout<<"<";
        node<t> *newnode=head;
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
 template <class t>
 void linklist<t>::Clear(){
  moveToStart();
 int z=length;
 while(z!=0){
    int a=Remove();
    z--;
 }
 cur=0;
 }
 template<class t>
void linklist<t>:: Append(t a){
 int k=cur;
moveToEnd();
Insert(a);
cur=k;
}

template <class t>
    void Queue<t>:: enqueue(t a){
        if(arr.Length()==0){
            arr.Insert(a);
        }
        else{
    arr.Append(a);}
    }
   template <class t>
    t Queue<t>::dequeue(){
    arr.moveToStart();
    t it=arr.Remove();
    return it;
    }
    template <class t>
    int Queue<t>::  length(){
    int it=arr.Length();
    return it;
    }
    template <class t>
    t Queue<t>::Front(){
    arr.moveToStart();
    t it=arr.getvalue();
    return it;
    }
    template <class t>
    t Queue<t>::Back(){
    arr.moveToEnd();
    t it=arr.getvalue();
    return it;
    }
    template <class t>
    bool Queue<t>::isEmpty(){
    if(arr.Length()==0){
        return true;
    }
    else return false;
    }
    template <class t>
    void Queue<t>::Clear(){
    arr.Clear();
    }
    template <class t>
    void Queue<t>::print(){
      if(arr.Length()==0){
    cout<<"<>"<<endl;
    return ;
 }
 else{
    cout<<"<";
        arr.moveToStart();
        for(int i=0;i<arr.Length()-1;i++) {
            cout<<arr.getvalue()<<" ";
                arr.next();
        }
        arr.next();
        cout<<arr.getvalue()<<">"<<endl;


 }
    }
