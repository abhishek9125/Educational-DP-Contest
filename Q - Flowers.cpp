#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct flower{
    int height;
    int beauty;
};

ll maxBeauty(vector<flower>& v,int n){
    vector<ll> dp(n+1);
    map<ll,ll> meaningful;
    dp[1] = v[1].beauty;
    meaningful[v[1].height] = dp[1];
    ll ans = dp[1];
    for(int i=2;i<=n;i++){
        dp[i] = v[i].beauty;
        auto it = meaningful.upper_bound(v[i].height);
        if(it != meaningful.begin()){
            it--;
            dp[i] = dp[i] + it->second;
        }
        meaningful[v[i].height] = dp[i];
        it = meaningful.upper_bound(v[i].height);
        while(it!=meaningful.end() && it->second<=dp[i]){
            auto temp = it;
            temp++;
            meaningful.erase(it);
            it = temp;  
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<flower> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i].height;
    }
    for(int i=1;i<=n;i++){
        cin>>v[i].beauty;
    }
    cout<<maxBeauty(v,n);
    return 0;
}

