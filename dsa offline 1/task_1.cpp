#include<bits/stdc++.h>
#include "array.cpp"
#include "list.cpp"
using namespace std;
int main(){
int k,x;
cin>>k>>x;
myarray Myarray(x);
linklist llist;
for(int i=0;i<k;i++){
    int a;
    cin>>a;
    Myarray.Insert(a);
    llist.Insert(a);
}
Myarray.print();
llist.print();
int q;
cin>>q;
while(q--){
    int p,r;
    cin>>p;
    if(p==1){
            cin>>r;
        Myarray.Insert(r);
        llist.Insert(r);
        Myarray.print();
        llist.print();
    }
    else if(p==2){
      int a=  Myarray.Remove();
     int b=  llist.Remove();
      cout<<"FROM ARRAY:"<<a<<endl;
   cout<<"FROM LIST:"<<b<<endl;
      Myarray.print();
llist.print();
    }
    else if(p==3){
    Myarray.moveToStart();
      llist.moveToStart();
      Myarray.print();
      llist.print();
    }
    else if(p==4){
        Myarray.moveToEnd();
        llist.moveToEnd();
         Myarray.print();
        llist.print();
    }
    else if(p==5){
        Myarray.prev();
           llist.prev();
           Myarray.print();
           llist.print();
    }
    else if(p==6){
        Myarray.next();
        llist.next();
        Myarray.print();
        llist.print();
    }
    else if(p==7){
        int a=Myarray.Length();
        cout<<"LENGTH OF ARRAY: "<<a<<endl;
          int b=llist.Length();
        cout<<"LENGTH OF LIST: "<<b<<endl;
    }
    else if(p==8){
        int a=Myarray.curPos();
        cout<<a<<endl;
           int b=llist.currPos();
        cout<<b<<endl;
    }
    else if(p==9){
            cin>>r;
            if(Myarray.Length()>=r){
           Myarray.moveToPos(r);}
           if(llist.Length()>=r){
          llist.moveTopos(r);}
          Myarray.print();
           llist.print();
    }
    else if(p==10){
      int a= Myarray.getValue();
      cout<<a<<endl;
          int b= llist.getvalue();
      cout<<b<<endl;
    }
    else {
        cout<<"NULL FUNCTION"<<endl;
    }
}
}
