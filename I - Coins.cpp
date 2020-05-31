#include<bits/stdc++.h>
#define prDouble(x) cout<< fixed << setprecision(10) << x
using namespace std;

double dp[3001][3001];
double probability(double* arr,int i,int x){
    if(x==0){
        return 1;
    }
    if(i==0){
        return 0;
    }
    if(dp[i][x]>-0.9){
        return dp[i][x];
    }

    return dp[i][x] = arr[i]*probability(arr,i-1,x-1) + (1 - arr[i])*probability(arr,i-1,x);
}

int main(){
    int n;
    cin>>n;
    double arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    prDouble(probability(arr,n,(n+1)/2));

    return 0;
}
