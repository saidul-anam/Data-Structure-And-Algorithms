#include<bits/stdc++.h>
using namespace std;
class Graph{
    int n=1;
map<int,vector<int>>arr,arr1;//arr for graph,arr 1 for traversegraph/inversegraph
vector<int>vertex;
map<int,bool>visited; // visited will call for arr
map<int,bool>traversevisited;// traversevisited will call for arr1
vector<int>arr3;// this vector will be used in traversing in dfs1
vector<int>arr4;
map<int,int>arr5;
map<int,bool>Final;//if assignment is possible this will store the the data whether a literal is true or false

//dfs for graph

    void dfs1(int v){
    visited[v]=true;
    for(auto a:arr[v]){
        if(!visited[a]){
            dfs1(a);
        }
    }
    arr3.push_back(v);
    }
    //dfs for inversegraph

    void dfs2(int v){
    traversevisited[v]=true;
    for(auto a:arr1[v]){
        if(!traversevisited[a]){
            dfs2( a);
        }
    }
    arr5[v]=n;
    }

public:
    void addedge(string s){
        int u,v;
        int a=0;
    if(s[1]=='\0'){
  u=s[0]-'a'+1;
  a=1;
    }
    else if(s[2]=='\0'){
        u=-s[1]+'a'-1;
        a=1;
    }
    else if(s[3]=='\0'){
        u=s[0]-'a'+1;
        v=s[2]-'a'+1;
    }
    else if(s[4]=='\0'){
        if(s[0]=='~'){
            u=-s[1]+'a'-1;
            v=s[3]-'a'+1;
        }
        else{
            u=s[0]-'a'+1;
            v=-s[3]+'a'-1;
        }
    }
    else{
        u=-s[1]+'a'-1;
        v=-s[4]+'a'-1;
    }
    if(a==1){
        arr[-u].push_back(u);
        arr1[u].push_back(-u);
        int z=0;
        for(int i=0;i<vertex.size();i++){
                if(u==vertex[i]){
                    z=1;
                    break;
                }
                }
                if(z==0){
                    vertex.push_back(u);
                }
                z=0;
                  for(int i=0;i<vertex.size();i++){
                if(-u==vertex[i]){
                    z=1;
                    break;
                }
                }
                if(z==0){
                    vertex.push_back(u);
                }

    }
    else{
        arr[-u].push_back(v);
        arr[-v].push_back(u);
        arr1[u].push_back(-v);
        arr1[v].push_back(-u);
         int z=0;
        for(int i=0;i<vertex.size();i++){
                if(u==vertex[i]){
                    z=1;
                    break;
                }
                }
                if(z==0){
                    vertex.push_back(u);
                }
                z=0;
                 for(int i=0;i<vertex.size();i++){
                if(-u==vertex[i]){
                    z=1;
                    break;
                }
                }
                if(z==0){
                    vertex.push_back(-u);
                }
            z=0;
        for(int i=0;i<vertex.size();i++){
                if(v==vertex[i]){
                    z=1;
                }
                }
                if(z==0){
                    vertex.push_back(v);
                }
                     z=0;
        for(int i=0;i<vertex.size();i++){
                if(-v==vertex[i]){
                    z=1;
                }
                }
                if(z==0){
                    vertex.push_back(-v);
                }
    }
    }

    void isScc(){
    for(int i=0;i<vertex.size();i++){
        if(!visited[vertex[i]]){
            dfs1(vertex[i]);
        }
    }
    for(int i=arr3.size()-1;i>=0;i--){
        int a=arr3[i];
        arr4.push_back(a);
        if(!traversevisited[a]){
            dfs2(a);
            n++;
        }
    }
    for(int i=0;i<vertex.size();i++){
        if(arr5[vertex[i]]==arr5[-vertex[i]]){
            cout<<"No assignment possible."<<endl;
            return;
        }
    }
    vector<int>arr6;
    for(int i=0;i<vertex.size();i++){
        if(vertex[i]>0){
            arr6.push_back(vertex[i]);
        }
    }
    for(int i=0;i<arr6.size();i++){
            int k=0;
        for(int j=0;j<arr4.size();j++){
            if(arr6[i]==arr4[j]){
                k=1;
                break;
            }
            if(arr6[i]==-arr4[j]){
                break;
            }
        }
        if(k==1){
           Final[arr6[i]]=false;
        }
        else{
            Final[arr6[i]]=true;
        }
    }
    map<int,bool>::iterator x;
    for(x=Final.begin();x!=Final.end();x++){
        if(x->second==false){
                char ans=x->first-1+'a';
            cout<<ans<<" : false"<<endl;
        }
        else{
                char ans=x->first-1+'a';
            cout<<ans<<" : true"<<endl;
        }
    }
    }
};
int main(){
int a;
cin>>a;
cin.ignore();
Graph arr;
    string s;
for(int i=1;i<=a;i++){
getline(cin,s);
    arr.addedge(s);
}
arr.isScc();
return 0;
}

