#include<bits/stdc++.h>
#include "Stack.cpp"
using namespace std;
int precedence(char c){
if(c=='-') return 1;
else if(c=='+')return 2;
else if(c=='/') return 4;
else if(c=='*')return 3;
else return -1;

}
int main(){
    string s;
    cin>>s;
    ///checking whether the input is valid or not
    Stack<char>x;   ///these stack is to check the parentheses
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            x.push(s[i]);
        }
        else if(s[i]==')'){
            if(x.isEmpty()){
                cout<<"INVALID"<<endl;
                return 0;
               }
               if(isdigit(s[i+1])){
                cout<<"INVALID"<<endl;
                return 0;
               }
               x.pop();
        }
       else if((s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-'||s[i]=='(')&&(s[i+1]=='+'||s[i+1]=='*'||s[i+1]=='/'||s[i+1]==')')){
                cout<<"INVALID"<<endl;
                return 0;
        }
      else  if(s[i]=='-'&&s[i+1]=='-'&&s[i+2]=='-'){
                 cout<<"INVALID"<<endl;
                return 0;
        }
    }
    if(!x.isEmpty()){
        cout<<"INVALID"<<endl;
        return 0;
    }
///end of checking validity .if the string is valid ,then it will not return.

    Stack<char>y;    ///it stores the operator
    Stack<double>z; ///it stores the value
    int j=0;
    bool neg; ///this bool is to determine a value is negative or not
    bool num=true;///this to determine the current character is a part of a number or not
    while(j<s.size()){
        neg=false;
        if(s[j]=='-'&&num==true){
            neg=true;
            j++;
        }
        if(isdigit(s[j])){
            string k;
            while(j<s.size()&&isdigit(s[j])){
                k=k+s[j];
                j++;
            }
            double n=stof(k);
            if(neg==true){
                n=-n;
            }
            neg=false;
            z.push(n);
            num=false;
        }
        else if(s[j]=='('){
                    y.push(s[j]);
                    j++;
                    num=true;
                }
                else if( s[j]==')' ){
                    while(!y.isEmpty()&&y.topValue()!='('){
                            char m=y.pop();
                            double n1=z.pop();
                            double n2=z.pop();
                            double n3=0.0;
                            if(m=='+'){
                                n3=n1+n2;
                            }
                            else if(m=='-'){
                                n3=n2-n1;
                            }
                            else if(m=='*'){
                                n3=n1*n2;
                            }
                            else if(m=='/'){
                                n3=n2/n1;
                            }
                            z.push(n3);

                          }
                          if(!y.isEmpty()&&y.topValue()=='('){
                                char m=y.pop();
                                num=false;
                             }
                             j++;
                             }
                else if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/')
                  {
                      while(!y.isEmpty()&&y.topValue()!='('&&precedence(y.topValue())>=precedence(s[j])){
                                              char m=y.pop();
                            double n1=z.pop();
                            double n2=z.pop();
                            double n3=0.0;
                            if(m=='+'){
                                n3=n1+n2;
                            }
                            else if(m=='-'){
                                n3=n2-n1;
                            }
                            else if(m=='*'){
                                n3=n1*n2;
                            }
                            else if(m=='/'){
                                n3=n2/n1;
                            }
                            z.push(n3);


                            }
                            y.push(s[j]);
                            num=true;
                            j++;
                  }
                  else{
                    num=false;
                    j++;
                  }
                }
                while(!y.isEmpty()){
                                    char m=y.pop();
                            double n1=z.pop();
                            double n2=z.pop();
                            double n3=0.0;
                            if(m=='+'){
                                n3=n1+n2;
                            }
                            else if(m=='-'){
                                n3=n2-n1;
                            }
                            else if(m=='*'){
                                n3=n1*n2;
                            }
                            else if(m=='/'){
                                n3=n2/n1;
                            }
                            z.push(n3);
                }
                cout<<"VALID"<<endl;
               double Ans=z.topValue();
                cout<<Ans<<endl;
                return 0;
}
