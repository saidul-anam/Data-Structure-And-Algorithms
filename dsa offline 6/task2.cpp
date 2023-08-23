#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int>*arr,vector<int>&arr1,vector<int>&vis,int source,int dest){
    if(source==dest){
            for(int it=dest;it!=-1;it=vis[it]){
                arr1.push_back(it);
            }
            reverse(arr1.begin(),arr1.end());
        return true;
    }
for(int x: arr[source]){
        if(vis[x]==0){
    vis[x]=source;
    dfs(arr,arr1,vis,x,dest);
    return true;
}
}
return false;
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
vector<int>vis(m,0);
vis[s]=-1;
vector<int>arr1;
if(dfs(arr,arr1,vis,s,d)){
int d=arr1.size();
output_file<<d-1<<endl;
for(int i=0;i<d;i++){
 output_file<<arr1[i]<<" ";
}
}
else{
    output_file<<"-1"<<endl;
}
}
