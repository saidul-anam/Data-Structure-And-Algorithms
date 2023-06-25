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
        Myarray.Clear();
        llist.Clear();
        Myarray.print();
        llist.print();
    }
    else if (p==2){
            cin>>r;
        Myarray.Append(r);
        llist.Append(r);
            Myarray.print();
        llist.print();
    }
    if(p==3){
        cin>>r;
      int a=Myarray.Search(r);
        int b=llist.Search(r);
cout<<"FOR ARRAY:"<<a<<endl;
cout<<"FOR LIST:"<<b<<endl;
        Myarray.print();
        llist.print();
    }

}
return 0;
}

