#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int dp[100001];

int solve(int src){
    if(dp[src]!=-1){
        return dp[src];
    }

    bool leaf = true;
    int bestChild = 0;
    for(int c: graph[src]){
        leaf = 0;
        bestChild = max(bestChild,solve(c));
    }
    return dp[src] = leaf ? 0 : 1 + bestChild;
}

int main() 
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        graph[s].push_back(e);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,solve(i));
    }
    cout<<ans;
    return 0;
}

