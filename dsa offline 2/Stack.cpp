#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Stack{
t *arr;
int length,capasity;


void Insert(t a){
    if(capasity==0){
        capasity=1;
        arr=new t[capasity];
    }
    if(length>=capasity){
        capasity=2*capasity;
        t *new_arr=new t[capasity];
        for(int i=0;i<length;i++){
            new_arr[i]=arr[i];
        }
        delete[] arr;
        arr=new_arr;
    }
arr[length]=a;
length++;
}
public:
    void init(){
    length=capasity=0;}
    Stack(){
    init();
    }
    Stack(int a){
    capasity=a;
    length=0;
    arr=new t[capasity];
    }
    ~Stack(){
    delete []arr;
    }
t pop(){
    if(length==0){
        return -1;
    }
    t a=arr[length-1];
  arr[length-1]='\0';
    length--;
    return a;
  }
  t topValue(){
      if(length==0){
        return 0;
      }
  return arr[length-1];
  }
int Length(){
return length;}
bool isEmpty(){
if(length>0){
    return false;
}
else return true;
}
void Clear(){
int z=length;
while(z!=0){
    int a=pop();
    z--;
}
}
void push(t a){
Insert(a);
}
};
