#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
    int n = A.size();
    vector<vector<ll>> C(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int x=0;x<n;x++){
                C[i][j] = (C[i][j] + A[i][x]*B[x][j]) % mod;    
            } 
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>>& matrix,ll exp){
    if(exp==1){
        return matrix;
    }
    vector<vector<ll>> result = power(matrix,exp/2);
    if(exp&1){
        return multiply(multiply(matrix,result),result);
    }
    else{
        return multiply(result,result);
    }
}

ll totalPaths(vector<vector<ll>>& adj,ll k,int n){
    vector<vector<ll> > ak = power(adj,k);
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = (ans + ak[i][j]) % mod;
        }
    }
    return ans;
}

int main(){
    int n;
    ll k;
    cin>>n>>k;
    vector<vector<ll> > adj(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    cout<<totalPaths(adj,k,n);
    return 0;
}

