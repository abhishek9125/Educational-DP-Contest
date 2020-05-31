#include<iostream>
#include<climits>
using namespace std;

int minCost(int n,int* arr,int k)
{
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    for(int i=2;i<n;i++)
    {
        int ans = INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i<j){
                break;
            }
            int option = abs(arr[i] - arr[i-j]) + dp[i-j];
            ans = min(ans,option);
        }
        dp[i] = ans;
    }
    return dp[n-1];
    
}

int main() 
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minCost(n,arr,k);
    return 0;
}

