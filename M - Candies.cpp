#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int candies(vector<int>& v,int n,int k){
    ll dp[n+2][k+2];

    for(int j=0;j<=k;j++){
        dp[1][j] = (j>v[1]) ? 0 : 1; 
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = (mod + dp[i][j-1] + dp[i-1][j] - ((j-1-v[i]>=0) ? dp[i-1][j-1-v[i]] : 0)) % mod;
            }
        }
    }
    return dp[n][k];
}

int candies2(vector<int>& v,int n,int k,int i,int j)

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    cout<<candies(v,n,k);
    return 0;
}
