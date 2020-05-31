#include<iostream>
#include<climits>
using namespace std;

int maxHappiness(int n,int** arr)
{
    int dp[n][3];
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i=1;i<n;i++){
        dp[i][0] = arr[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = arr[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = arr[i][2] + max(dp[i-1][0],dp[i-1][1]);
    }
    int ans = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    return ans;
}

int main() 
{
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[3];
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<maxHappiness(n,arr);
    return 0;
}

