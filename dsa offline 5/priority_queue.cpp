#include<bits/stdc++.h>
using namespace std;
template<class t>
class priority__queue{
int node;
t *arr;
int capasity;
void max_heapify_up(int i){
int parent=i/2;
if(parent>0&&arr[parent]<arr[i]){
    t temp=arr[i];
    arr[i]=arr[parent];
    arr[parent]=temp;
   max_heapify_up(parent);
}
}
void     max_heapify_down(int i){
int l=2*i;
int r=2*i+1;
int largest;
if(l<=node&&arr[l]>arr[i]){
    largest=l;
}
else{
    largest=i;
}
if(r<=node&&arr[largest]<arr[r]){
    largest=r;
}
if(largest!=i){
        t temp=arr[i];
    arr[i]=arr[largest];
    arr[largest]=temp;
        max_heapify_down(largest);
}
}
public:
    priority__queue(){
    node=0;
    capasity=100;// by default
    arr=new t[100];
    }
 void Insert(t value){
 if(node==capasity-1){
    t *new_arr=new t[2*capasity];
    capasity=2*capasity;
    for(int i=1;i<=node;i++){
        new_arr[i]=arr[i];
    }
    delete arr;
    arr=new_arr;
 }
 node++;
 arr[node]=value;
 max_heapify_up(node);
 }
 t findmax(ofstream& output_file){
 if(node==0){
    output_file<<"No element found"<<endl;
    return -1;
 }
 else{
    return arr[1];
 }
 }
 t extractmax(){
 t k=arr[1];
 arr[1]=arr[node];
 node--;
     max_heapify_down(1);
return k;
 }
 void increasekey(int n,t value,ofstream& output_file){
     if(node<n){
        output_file<<"Not found"<<endl;
        return;
     }
     if(value<arr[n]){
        output_file<<"New key is not larger than the previous key"<<endl;
        return;
     }
     output_file<<"Key increased!"<<endl;
     arr[n]=value;
    max_heapify_up(n);
 }
void decreasekey(int n,t value,ofstream& output_file){
      if(node<n){
        output_file<<"Not found"<<endl;
        return;
     }
     if(value>arr[n]){
        output_file<<"New key is not smaller than the previous key"<<endl;
        return;
     }
     output_file<<"Key decreased!"<<endl;
     arr[n]=value;
         max_heapify_down(n);
}
void Sort(){
    int z=node;
for(int i=1;i<=z;i++){
    int k=extractmax();
    arr[z-i+1]=k;
}
node=z;
}
void print(ofstream& output_file){
    output_file<<"No of elements: "<<node<<endl;
for(int i=1;i<=node;i*=2){
        for(int j=1;j<=i&&(i+j-1)<=node;j++){
                if(i==1){
                    output_file<<arr[1];
                }
                else{
    output_file<<arr[j+i-1]<<"\t";
                }
}
output_file<<endl;
}
}
};
int main(){
     ifstream input_file("in.txt");
    ofstream output_file("out.txt");

priority__queue<int> arr;
int k;
while(input_file>>k){
    if(k==1){
        int a;
        input_file>>a;
        arr.Insert(a);
    }
   else if(k==2){
    output_file<<"Max: "<<arr.findmax(output_file)<<endl;
   }
   else if(k==3){
    output_file<<"Max: "<<arr.extractmax()<<" has been extracted."<<endl;
   }
   else if(k==4){
    int a,b;
    input_file>>a>>b;
  arr.increasekey(a,b,output_file);

   }
   else if (k==5){
     int a,b;
    input_file>>a>>b;
  arr.decreasekey(a,b,output_file);

   }
   else if(k==6){
    arr.print(output_file);
   }
   else if(k==7){
    arr.Sort();
    arr.print(output_file);
    break;
   }
}
}

