
#include<bits/stdc++.h>
#include "Stack.cpp"
using namespace std;

int main(){
int m,n;
cin>>m>>n;
Stack<char>arr(m);

for(int i=0;i<n;i++){
      char c;
    cin>>c;
    arr.push(c);
}
int a;

while(cin>>a){
    if(a==1){
        arr.Clear();
    }
    else if(a==2){
            int b;
    cin>>b;
        arr.push(b);
    }
       else if(a==3){
        int x=arr.pop();
        cout<<x<<endl;
    }
       else if(a==4){
        int x=arr.Length();
        cout<<x<<endl;
    }
       else if(a==5){
        int x=arr.topValue();
        cout<<x<<endl;
    }
       else if(a==6){
        bool z=arr.isEmpty();
        cout<<z<<endl;
    }
       else if(a==0){
        break;
    }
       else {
        cout<<"FUNCTION NOT VALID"<<endl;
    }
}
return 0;
}
