#include "2_stack.cpp"
int main(){
Stack<int>hi;
int a;
while(cin>>a){
    if(a==1){
        int p;
        cin>>p;
        hi.push(p);
        hi.print();
    }
  if(a==2)  {
   int x= hi.pop();
   cout<<x<<endl;
   hi.print();
  }
   if(a==3){
    int b=hi.Length();
    cout<<b<<endl;
    hi.print();
   }
   if(a==4){
    int b=hi.topValue();
    cout<<b<<endl;
    hi.print();
   }
   if(a==5){
    int b=hi.isEmpty();
    cout<<b<<endl;
   hi.print();
   }
   if(a==6){
    hi.Clear();
    hi.print();
   }
   if(a==0){
    break;
   }
}
}
