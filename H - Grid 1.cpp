#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

char grid[1002][1002];

int paths(int n,int m){
    int dp[1002][1002];
    memset(dp,-1,sizeof(dp));
    int counter = 1;
    for(int i=0;i<m;i++){
        if(grid[0][i]=='#'){
            dp[0][i] = 0;
            counter = 0;
        }
        if(grid[0][i]=='.' && counter==1){
            dp[0][i] = 1;
        }
        if(counter==0){
            dp[0][i] = 0;
        }
    }
    counter = 1;
    for(int i=0;i<n;i++){
        if(grid[i][0]=='#'){
            dp[i][0] = 0;
            counter = 0;
        }
        if(grid[i][0]=='.' && counter==1){
            dp[i][0] = 1;
        }
        if(counter==0){
            dp[i][0] = 0;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(grid[i][j]=='.'){
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return dp[n-1][m-1];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<paths(n,m);
    return 0;
}
