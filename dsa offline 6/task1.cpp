#include<bits/stdc++.h>
using namespace std;
vector<int>bfs(vector<int>*arr,int v,int s,int d){
    vector<int>arr1;
    vector<int>vis(v,0);
    vector<int>parent(v,0);
    queue<int>q;
    q.push(s);
    vis[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto x:arr[temp]){
            if(vis[x]==0){
                vis[x]=vis[temp]+1;
                parent[x]=temp;
                q.push(x);
                if(x==d){
                    for(auto it=d;it!=-1;it=parent[it]){
                        arr1.push_back(it);
                    }
                    reverse(arr1.begin(),arr1.end());
                    return arr1;
                }

            }
        }
    }
   return arr1;
}
int main(){
     ifstream input_file("in.txt");
    ofstream output_file("out.txt");
int m,n;
input_file>>m>>n;
vector<int>arr[m];
for(int i=0;i<n;i++){
    int a,b;
    input_file>>a>>b;
    arr[a].push_back(b);
}
int s,d;
input_file>>s>>d;
vector<int>arr1=bfs(arr,m,s,d);
int l=arr1.size();
int k=-1;
for(int i=1;i<l;i++){
    if(arr1[i]==d){
        k=i;
        break;
    }

}
if(k!=-1){
    output_file<<k<<endl;
    for(int i=0;i<=k;i++){
    output_file<<arr1[i]<<" ";
    }}
    else{
        output_file<<k<<endl;
    }
}
