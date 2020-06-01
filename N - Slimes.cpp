#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3001][3001];
ll sum[3001][3001];

ll slimes(vector<ll>& v,int i,int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll minCost = 1000000000000000;
    for(int k=i;k<j;k++){
        minCost = min(minCost,sum[i][j] + slimes(v,i,k) + slimes(v,k+1,j));
    }
    return dp[i][j] = minCost;
}

int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum[i][j] = v[j] + ((j==i) ? 0 : sum[i][j-1]);
        }
    }
    cout<<slimes(v,0,n-1);
    return 0;
}

