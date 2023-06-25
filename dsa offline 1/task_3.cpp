#include<bits/stdc++.h>
#include "array.cpp"
#include "list.cpp"
using namespace std;
int main(){
int car;
cin>>car;
int garage;
cin>>garage;
int park;
cin>>park;
linklist *garages=new linklist[garage+1];
for(int i=1;i<garage+1;i++){
    int a;
    cin>>a;
garages[a].init();
    int b;
    cin>>b;
    for(int j=0;j<b;j++){
            int c;
    cin>>c;
        garages[a].Insert(c);
    }
}
for(int k=1;k<garage+1;k++){
    garages[k].print();
}
        string s;
while(cin>>s){
        if(s=="end"){
            break;
        }
   else if(s=="req"){
        int g=-1;
       for(int i=1;i<garage+1;i++){
        if(garages[i].Length()!=0){
            int k=park;
            g=1;
            int m=garages[i].Length();
            for(int j=1;j<=m;j++){
                garages[i].moveTopos(j);
                int z=garages[i].getvalue();
               if(z<k){
                k=z;
                g=j;
               }
            }
            garages[i].moveTopos(g);
           int x=garages[i].Remove();
           garages[i].moveToStart();
           break;
        }
       }
       if(g!=-1){
        for(int i=1;i<garage+1;i++){
         garages[i].print();
}
       }
       else {
        cout<< "all garages are empty"<<endl;
       }
   }
        else if(s=="ret"){
            int val;
            cin>>val;
            for(int i=garage;i>=1;i--){
                if(garages[i].Length()!=park&&garages[i].Length()>0){

                      int k=0;
                      int g=1;
            int m=garages[i].Length();
            for(int j=1;j<=m;j++){
                garages[i].moveTopos(j);
                int z=garages[i].getvalue();
               if(z>k){
                k=z;
                g=j;
               }
            }
            garages[i].moveToStart();
            garages[i].moveTopos(g);
            garages[i].Insert(val);
             garages[i].moveToStart();
            break;
                }
                else if(garages[i].Length()==0){
                    garages[i].Insert(val);
                    break;
                }
            }
            for(int i=1;i<garage+1;i++){
           garages[i].print();
}
        }
}
return 0;
}
