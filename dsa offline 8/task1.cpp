#include<iostream>
#include<vector>
#include <fstream>
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
pair<int,int>mid;
int crosscheck(pair<int,int>a,pair<int,int>b,pair<int,int>c){
return ((b.second-a.second)*(c.first-b.first)-(c.second-b.second)*(b.first-a.first));
}
int hell(pair<int,int>a){
if(a.first-mid.first>=0&&a.second-mid.second>=0)  return 1;
if(a.first-mid.first<=0&&a.second-mid.second>=0)return 2;
if(a.first-mid.first<=0&&a.second-mid.second<=0) return 3;
return 4;
}
bool compare(pair<int,int>a,pair<int,int>b){
int i=a.first-mid.first;
int j=a.second-mid.second;
int k=b.first-mid.first;
int l=b.second-mid.second;
if(hell(a)!=hell(b)) return hell(a)<hell(b);
else return j*k<i*l;
}
vector<pair<int,int>>conq(vector<pair<int,int>>a,vector<pair<int,int>>b){
    int leftmost=0;
    int rightmost=0;
for(int i=1;i<a.size();i++){
if(a[i].first>a[rightmost].first){
    rightmost=i;
}
}
 for(int i=1;i<b.size();i++){
if(b[i].first<b[leftmost].first){
    leftmost=i;
}
}
    int lb=leftmost,la=rightmost;
bool x=0;
while(!x){
    x=1;
    while(crosscheck(b[lb],a[la],a[(la+1)%a.size()])>=0){
        la=(la+1)%a.size();
    }
     while(crosscheck(a[la],b[lb],b[(lb+b.size()-1)%b.size()])<=0){
        lb=(lb+b.size()-1)%b.size();
        x=0;
    }
}
int top1=la,top2=lb;
la=rightmost;
lb=leftmost;
x=0;
while(!x){
    x=1;
     while(crosscheck(a[la],b[lb],b[(lb+1)%b.size()])>=0){
     lb=(lb+1)%b.size();
    }
     while(crosscheck(b[lb],a[la],a[(la+a.size()-1)%a.size()])<=0){
        la=(la+a.size()-1)%a.size();
        x=0;
    }
}
int low1=la,low2=lb;
vector<pair<int,int>>arr3;
arr3.push_back(a[top1]);
int k=top1;
while(k!=low1){
    k=(k+1)%a.size();
    arr3.push_back(a[k]);
}
k=low2;
arr3.push_back(b[low2]);
while(k!=top2){
    k=(k+1)%b.size();
    arr3.push_back(b[k]);
}
return arr3;
}
vector<pair<int,int>>divide(vector<pair<int,int>>arr){
vector<pair<int,int>>arr1;
set<pair<int,int>>set1;
int a=arr.size();
for(int i=0;i<a;i++){
    for(int j=i+1;j<a;j++){
        int x=arr[j].first-arr[i].first;
        int y=arr[i].second-arr[j].second;
        int c=arr[i].first*arr[j].second-arr[i].second*arr[j].first;
        int left=0;
        int right=0;
        for(int k=0;k<a;k++){
            if(x*arr[k].second+y*arr[k].first+c>=0){
                right=right+1;
            }
            if(x*arr[k].second+y*arr[k].first+c<=0){
                left=left+1;
            }
        }
        if(left==a||right==a){
            set1.insert(arr[i]);
            set1.insert(arr[j]);
        }
    }
}
mid={0,0};
for(auto i:set1){
    arr1.push_back(i);
}
for(int i=0;i<arr1.size();i++){
    mid.first+=arr1[i].first;
    mid.second+=arr1[i].second;
    arr1[i].first=arr1[i].first*arr1.size();
    arr1[i].second=arr1[i].second*arr1.size();
}
sort(arr1.begin(),arr1.end(),compare);
for(int i=0;i<arr1.size();i++){
    arr1[i].first=arr1[i].first/arr1.size();
    arr1[i].second=arr1[i].second/arr1.size();
}
return arr1;
}
vector<pair<int,int>>divide_conq(vector<pair<int,int>>arr){
    int a=arr.size();
    if(a<=5){
        return divide(arr);
    }
    vector<pair<int,int>>left;
    vector<pair<int,int>>right;
    for(int i=0;i<a/2;i++){
        left.push_back(arr[i]);
    }
    for(int i=a/2;i<a;i++){
        right.push_back(arr[i]);
    }
vector<pair<int,int>>arr1=divide_conq(left);
vector<pair<int,int>>arr2=divide_conq(right);
return conq(arr1,arr2);
}
int main(){
      ifstream input_file("in.txt");
    ofstream output_file("out.txt");
int n ;
input_file>>n;
vector<pair<int,int>>arr;
for(int i=0;i<n;i++){
    int x,y;
    input_file>>x>>y;
    arr.push_back(make_pair(x,y));
}
sort(arr.begin(),arr.end());
vector<pair<int,int>>arr1=divide_conq(arr);
for(int i=0;i<arr1.size();i++){
    output_file<<arr1[i].first<<" "<<arr1[i].second<<endl;
}
}
