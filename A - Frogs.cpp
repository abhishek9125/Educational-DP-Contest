#include <iostream>
using namespace std;

int minCost(int n,int* arr)
{
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for(int i=2;i<n;i++)
    {
        int option1 = abs(arr[i] - arr[i-1]) + dp[i-1];
        int option2 = abs(arr[i] - arr[i-2]) + dp[i-2];
        dp[i] = min(option1,option2);
    }
    cout<<endl;

    return dp[n-1];
    
}

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minCost(n,arr);
    return 0;
}

