#include<bits/stdc++.h>
using namespace std;

string winner(vector<int>& v,int n,int k){
    bool dp[k+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++){
        for(int cut: v){
            if(cut>i){
                continue;
            }
            if(dp[i-cut]==0){
                dp[i] = 1;
            }
        }
    }
    return dp[k] ? "First" : "Second";
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<winner(v,n,k);
    return 0;
}
