#include "2_stack.h"
template<class t>
  t Stack<t>:: pop(){
    int a=arr.length();
    for(int i=0;i<a-1;i++){
        temp.enqueue(arr.dequeue());
    }
    t n=arr.dequeue();
    for(int i=0;i<a-1;i++){
        arr.enqueue(temp.dequeue());
    }
    return n;
    }
    template<class t>
  t  Stack<t>::topValue(){
      if(arr.length()==0){
        return 0;
      }
      int a=arr.Back();
  return a;
  }
  template<class t>
int  Stack<t>::Length(){
return arr.length();}
template<class t>
bool  Stack<t>::isEmpty(){
if(arr.length()>0){
    return false;
}
else return true;
}
template<class t>
void  Stack<t>::Clear(){
arr.Clear();
}
template<class t>
void  Stack<t>::push(t a){
Insert(a);
}
template<class t>
void  Stack<t>::print(){
arr.print();
}
