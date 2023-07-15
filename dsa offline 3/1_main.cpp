#include"1_a_queue.cpp"
int main(){
AQueue<int>hi;
int a;
while(cin>>a){
    if(a==1){
        int p;
        cin>>p;
        hi.enqueue(p);
        hi.print();
    }
  if(a==2)  {
   int x= hi.dequeue();
   cout<<x<<endl;
   hi.print();
  }
   if(a==3){
    int b=hi.length();
    cout<<b<<endl;
    hi.print();
   }
   if(a==4){
    int b=hi.Front();
    cout<<b<<endl;
    hi.print();
   }
   if(a==5){
    int b=hi.Back();
    cout<<b<<endl;
    hi.print();
   }
   if(a==6){
    int b=hi.isEmpty();
    cout<<b<<endl;
   hi.print();
   }
   if(a==7){
    hi.Clear();
    hi.print();
   }
   if(a==0){
    break;
   }
}
}
