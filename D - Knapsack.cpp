#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll knapsack(int* v,int* w,int W,int n){
    ll dp[n+1][W+1];
    for(int i=0;i<=W;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int wt=0;wt<=W;wt++){
            dp[i][wt] = dp[i-1][wt];
            if(w[i-1]<=wt){
                dp[i][wt] = max(dp[i][wt],v[i-1] + dp[i-1][wt - w[i-1]]);
            }
        }
    }
    return dp[n][W];
}

int main(){
    int n,W;
    cin>>n>>W;
    int v[n],w[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<knapsack(v,w,W,n);
    return 0;
}

