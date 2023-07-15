#include<bits/stdc++.h>
#include"1_a_queue.h"
template<typename t>
  void myarray<t>::init(){
    cur=length=0;
    capasity=1;
    arr=new t[1];
    }
  template<typename t>
  myarray<t>::myarray(){
    init();
    }
    template<typename t>
  myarray<t>::myarray(int a){
    capasity=a;
    length=cur=0;
    arr=new t[capasity];
    }
     template<typename t>
  myarray<t>:: ~myarray(){
    delete []arr;
    }
  template<typename t>
  void myarray<t>:: Insert(t a){
    if(length>=capasity){
        capasity=2*capasity;
        t *new_arr=new t[capasity];
        for(int i=0;i<length;i++){
            new_arr[i]=arr[i];
        }
        delete[] arr;
        arr=new_arr;
    }
    if(cur==0){
        cur=1;
    }
for(int i=length-1;i>=cur-1;i--){
    arr[i+1]=arr[i];
}
arr[cur-1]=a;
length++;
cur++;
}
    template<typename t>
 t myarray<t>:: Remove(){
    t a=arr[cur-1];
for(int i=cur-1;i<length;i++){
    arr[i]=arr[i+1];
}
    length--;
    return a;
  }
   template<typename t>
  int myarray<t>::Length(){
return length;}
  template<typename t>
 void myarray<t>::moveToEnd(){
cur=length;}

  template<typename t>
  void myarray<t>::moveToStart(){
cur=1;}
     template<typename t>
  void myarray<t>:: prev(){
if(cur!=1){
    cur--;
}
}
  template<typename t>
   void myarray<t>::next(){
if(cur!=length){
    cur++;
}
}
  template<typename t>
  t myarray<t>:: getValue(){
    if(cur>length||length==0){
        return 0;
    }
    else{
return arr[cur-1];}
}
  template<typename t>
   int myarray<t>:: curPos(){
return cur;}
  template<typename t>
  void myarray<t>:: moveToPos(int a){
if(a>=0&&a<length){
    cur=a;
}
}
  template<typename t>
  void myarray<t>:: print(){
if(length==0){
    cout<<"<>"<<endl;
}
else{
    cout<<"<";
    for(int i=0;i<cur-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"|";
    for(int i=cur-1;i<length-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[length-1]<<">"<<endl;
}
}
  template<typename t>
  void myarray<t>::Clear(){
moveToStart();
int z=length;
while(z!=1){
    int a=Remove();
    z--;
}
moveToPos(1);
}
  template<typename t>
   int myarray<t>::Capasity(){
return capasity;}
  template<typename t>
  void myarray<t>:: setcap(int b){
capasity=2*b;
arr=new t[b];}


template <typename t>
AQueue<t>::AQueue(){
    Rear=0;
    frront=1;
    arr.Insert(0);
    }
    template <typename t>
  t AQueue<t>:: enqueue(t a){
        if(length()==0){
            arr.Insert(a);
        }
        if(length()<arr.Capasity()){
    Rear=Rear+1;
    int b=arr.Capasity();
    Rear=Rear%b;
    arr.moveToPos(Rear);
    arr.Insert(a);}
    else{
    int b=arr.Capasity();
    arr.setcap(b);
        Rear=Rear+1;
    int c=arr.Capasity();
    Rear=Rear%c;
    arr.moveToPos(Rear);
    arr.Insert(a);
    }
    }

    template <typename t>
   t AQueue<t>:: dequeue(){
        int a=arr.Capasity();
    arr.moveToPos(frront);
    t it=arr.getValue();
    frront=(frront+1)%a;
    return it;
    }
    template <typename t>
    int AQueue<t>::length(){
        int a=arr.Capasity();
    int it=((Rear+a)-frront+1)%a;
    return it;
    }
   template <typename t>
   t AQueue<t>::Front(){
    arr.moveToPos(frront);
    t it=arr.getValue();
    return it;
    }
    template <typename t>
    t AQueue<t>::Back(){
    arr.moveToPos(Rear);
    t it=arr.getValue();
    return it;
    }
   template <typename t>
   bool AQueue<t>::isEmpty(){
    if(arr.Length()==0){
        return true;
    }
    else return false;
    }
    template <typename t>
    void AQueue<t>::Clear(){
    arr.Clear();
    Rear=0;
    frront=1;
    arr.setcap(1);
    }
    template <typename t>
   void AQueue<t>:: print(){
        int a=length();
    if(a==0){
    cout<<"<>"<<endl;
}
else{
    cout<<"<";
    if(frront>Rear){
            int z=a-frront-Rear;
    for(int i=frront;i<z;i++){
   arr.moveToPos(i+1);
   t it=arr.getValue();
   cout<<it<<" ";
    }
    for(int i=0;i<Rear-1;i++){
          arr.moveToPos(i+1);
   t it=arr.getValue();
   cout<<it<<" ";
    }
   arr.moveToPos(Rear);
   t it=arr.getValue();
    cout<<it<<">"<<endl;
}
else{
    for(int i=frront;i<Rear;i++){
        arr.moveToPos(i);
        t it=arr.getValue();
        cout<<it<<" ";
    }
    arr.moveToPos(Rear);
    t it=arr.getValue();
    cout<<it<<">"<<endl;
}
    }
    }
    template <typename t>
   int AQueue<t>::ok(){
    int a=arr.Capasity();
    return a;
    }
