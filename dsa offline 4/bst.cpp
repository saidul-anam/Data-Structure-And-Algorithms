#include<bits/stdc++.h>
using namespace std;
template<class t>
class binnode{
public:
t value;
binnode<t>*left;
binnode<t>*right;
    binnode(t a,binnode<t>*l=NULL,binnode<t>*r=NULL){
    value=a;
    left=l;
    right=r;
    }
};
template<class t>
class bst{
int Count;
binnode<t>*root;
int z;
 binnode<t>*InsertHelp(binnode<t>*x,t a){
    if(x==NULL){
        x=new binnode<t>(a);
        Count++;
     }
     else if(a>=x->value){
        x->right=InsertHelp(x->right,a);
     }
     else{
        x->left=InsertHelp(x->left,a);
     }
     return x;
     }
     bool FindHelp(binnode<t>*x,t a){
     if(x==NULL){
        return false;
     }
     else if(a>x->value){
        return FindHelp(x->right,a);
     }
     else if(a<x->value){
        return FindHelp(x->left,a);
     }
     else{
        return true;
     }
     }

     binnode<t>*Min(binnode<t>*x){
     if(x==NULL){
        return NULL;
     }
     if(x->left==NULL){
        return x;
     }
        return Min(x->left);

     }

     binnode<t>*DeleteHelp(binnode<t>*x,t a){
    if(x==NULL){
        return x;
    }
    else if(a>x->value){
        x->right= DeleteHelp(x->right,a);
    }
    else if(a<x->value){
        x->left=DeleteHelp(x->left,a);
    }
    else{
        if(x->left==NULL&&x->right==NULL){
            delete x;
            Count--;
            x= NULL;
        }
        else if(x->left==NULL){
                        binnode<t>*temp=x;
            x=x->right;
            delete temp;
            Count--;
        }
        else if(x->right==NULL){
                    binnode<t>*temp=x;
            x=x->left;
            delete temp;
            Count--;
        }
        else{
            binnode<t>*temp1=Min(x->right);
            x->value=temp1->value;
            x->right=DeleteHelp(x->right,temp1->value);
            Count--;

        }
        return x;
    }
     }
 public:
     bst(){
     Count=0;
     root=NULL;
      z=1;
     }
     void Insert(t a){
     root=InsertHelp(root,a);
     Count++;
     }
     bool Find(t a){
     return FindHelp(root,a);
     }
     void Delete(t a){
           if(!Find(a)){
            return;
         }
     root=DeleteHelp(root,a);
     }
        void print(binnode<t>*x,ofstream& output_file){
       if(x==NULL){
        return;
       }
       if(z==1){
       output_file<<x->value;}
       if(x->left==NULL&&x->right==NULL){
        return ;
       }
       if(x->value==x->right->value){
        z=z+1;
       }
       else{
        output_file<<"["<<z<<"]";
        z=1;
       }
       output_file<<"(";
       print(x->left,output_file);
       output_file<<",";
       print(x->right,output_file);
       output_file<<")";
   }
        void preorder(binnode<t>*x,ofstream& output_file){
         if(x==NULL){
            return ;
         }
     output_file<<x->value;
     output_file<<" ";
     preorder(x->left,output_file);
     preorder(x->right,output_file);
     }
   void inorder(binnode<t>*x,ofstream& output_file){
          if(x==NULL){
            return ;
         }
   inorder(x->left,output_file);
   output_file<<x->value<<" ";
   inorder(x->right,output_file);
   }
   void postorder(binnode<t>*x,ofstream& output_file){
          if(x==NULL){
            return ;
         }
   postorder(x->left,output_file);
   postorder(x->right,output_file);
   output_file<<x->value<<" ";
   }
   binnode<t>*getroot(){
   return root;}
};
int main(){
    ifstream input_file("in.txt");
    ofstream output_file("out.txt");

    bst<int>arr;
string s;
while(input_file>>s){
    if(s=="I"){
            int a;
    input_file>>a;
        arr.Insert(a);
        output_file<<"(";
        arr.print(arr.getroot(),output_file);
        output_file<<")\n";

    }
    else if(s=="F"){
        int a;
        input_file>>a;
        if(!arr.Find(a)){
            output_file<<"NOT FOUND\n";
        }
        else{
            output_file<<"FOUND\n";
        }
    }
    else if(s=="D"){
        int a;
        input_file>>a;
        arr.Delete(a);
        output_file<<"(";
        arr.print(arr.getroot(),output_file);
        output_file<<")\n";
    }
    else if(s=="T"){
        string a;
        input_file>>a;
        if(a=="Pre"){
            arr.preorder(arr.getroot(),output_file);
            output_file<<"\n";
        }
        else if(a=="In"){
                arr.inorder(arr.getroot(),output_file);
            output_file<<"\n";
        }
        else if(a=="Post"){
            arr.postorder(arr.getroot(),output_file);
            output_file<<"\n";
        }
    }
}
input_file.close();
output_file.close();
}
