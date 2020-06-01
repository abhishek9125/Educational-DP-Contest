#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

vector<int> tree[100001];
ll dp[100001][2];

ll totalWays(int src,bool constraint,int parent){
    if(dp[src][constraint]!=-1){
        return dp[src][constraint];
    }
    ll ans = 0;
    ll w1 = 1;
    for(int child: tree[src]){
        if(child!=parent){
            w1 = (w1 * totalWays(child,0,src))% mod;
        }
    }
    ans += w1;
    
    if(!constraint){  
        ll w2 = 1;  
        for(int child: tree[src]){
            if(child!=parent){
                w2 = (w2 * totalWays(child,1,src))% mod;
            }
        }
        ans = (ans + w2)% mod;   
    }
    return dp[src][constraint] = ans;
}

int main() 
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout<<totalWays(1,0,-1);
    return 0;
}

