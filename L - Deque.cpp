#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3001][3001];

ll score(vector<ll>& v,int i,int j,bool turn){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(turn==1){
        return dp[i][j] = max(v[i] + score(v,i+1,j,0),v[j] + score(v,i,j-1,0));
    }
    else{
        return dp[i][j] = min(score(v,i+1,j,1),score(v,i,j-1,1));
    }
}

int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }
    ll scoreX = score(v,0,n-1,1);
    ll scoreY = sum - scoreX;
    cout<<scoreX - scoreY;
    return 0;
}
