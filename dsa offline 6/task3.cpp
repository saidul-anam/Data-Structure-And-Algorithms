#include<bits/stdc++.h>
using namespace std;
#define INF 10e9+1
int x[]={1,1,2,2,-1,-1,-2,-2};
int y[]={2,-2,1,-1,2,-2,1,-1};
vector<vector<int>>moves(10000,vector<int>(10000,-1));
void bfs(int r,int c,int a,int b,int k){
    vector<vector<int>>moves1(10000,vector<int>(10000,INF));
moves1[a][b]=0;
queue<pair<int,int>>q;
q.push({a,b});
while(!q.empty()){
    int d=q.front().first;
    int e=q.front().second;
    q.pop();
    for(int i=0;i<8;i++){
        for(int j=1;j<=k;j++){
            int f=d+j*x[i];
            int g=e+j*y[i];
            if((f>=0&&f<r)&&(g>=0&&g<c)){
                if(moves1[f][g]>moves1[d][e]+1){
                    moves1[f][g]=moves1[d][e]+1;
                    q.push({f,g});
                }
            }
            else break;
        }
    }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
            if(moves1[i][j]==INF){
                moves[i][j]=INF;
            }

        if(moves1[i][j]!=INF&&moves[i][j]!=INF&&moves[i][j]==-1){
            moves[i][j]=moves1[i][j];
        }
        else if(moves1[i][j]!=INF&&moves[i][j]!=INF&&moves[i][j]!=-1){
            moves[i][j]=moves[i][j]+moves1[i][j];
        }
    }
}
}
int main(){
  ifstream input_file("in.txt");
    ofstream output_file("out.txt");
int r,c,q;
input_file>>r>>c>>q;
int Count =INT_MAX;
int m=0;
for(int i=0;i<q;i++){
    int a,b,k;
    input_file>>a>>b>>k;
     bfs(r,c,a,b,k);
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(moves[i][j]>0&&moves[i][j]!=INF){
            Count=min(Count,moves[i][j]);
            m=1;
        }
    }
}
if(m==0){
    output_file<<"-1"<<endl;
}
else output_file<<Count<<endl;
}
