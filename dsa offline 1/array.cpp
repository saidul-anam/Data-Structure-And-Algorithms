#include<bits/stdc++.h>
using namespace std;
class myarray{
int *arr;
int cur,length,capasity;
public:
    void init(){
    cur=length=capasity=0;}
    myarray(){
    init();
    }
    myarray(int a){
    capasity=a;
    length=cur=0;
    arr=new int[capasity];
    }
    ~myarray(){
    delete []arr;
    }
void Insert(int a){
    if(capasity==0){
        capasity=1;
        arr=new int[capasity];
    }
    if(length>=capasity){
        capasity=2*capasity;
        int *new_arr=new int[capasity];
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
}
int Remove(){
    int a=arr[cur-1];
for(int i=cur-1;i<length;i++){
    arr[i]=arr[i+1];
}
    length--;
    return a;
  }
int Length(){
return length;}
void moveToEnd(){
cur=length;}
void moveToStart(){
cur=1;}
void prev(){
if(cur!=1){
    cur--;
}
}
void next(){
if(cur!=length){
    cur++;
}
}
int getValue(){
    if(cur>length||length==0){
        return NULL;
    }
    else{
return arr[cur-1];}
}
int curPos(){
return cur;}
void moveToPos(int a){
if(a>=0&&a<length){
    cur=a;
}
}
void print(){
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
void Clear(){
moveToStart();
int z=length;
while(z!=0){
    int a=Remove();
    z--;
}
}
int Search(int a){
    int i;
for( i=0;i<length;i++){
    if(arr[i]==a){
        break;
    }
}
if(i<length){
    return i+1;
}
else{
    return NULL;
}
}
void Append(int a){
    int k=cur;
moveToEnd();
cur=cur+1;
Insert(a);
cur=k;
}
};
