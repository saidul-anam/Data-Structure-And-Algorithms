#include<iostream>
#include<vector>
#include <fstream>
#include <iostream>
#include<algorithm>
using namespace std;
int main(){
      ifstream input_file("in.txt");
    ofstream output_file("out.txt");

int n;
input_file>>n;
vector<int>arr(n);
vector<int>arr1(n);
for(int i=0;i<n;i++){
input_file>>arr[i]>>arr1[i];
}
sort(arr1.begin(),arr1.end());
sort(arr.begin(),arr.end());
int counter=1;
int i=1,j=0;
int ans=1;
while(i<n&&j<n){
    if(arr[i]<=arr1[j]){
        counter++;
        i++;
    }
    else{
            ans=max(ans,counter);
      counter--;
        j++;
    }
}
output_file<<ans<<endl;
}
