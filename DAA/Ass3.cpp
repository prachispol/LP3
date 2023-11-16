
#include<bits/stdc++.h>
using namespace std;

int main(){
    int W,n;
    cout<<"enter total number of items available";
    cin>>n;
    int wt[n];
    int val[n];
    cout<<"enter weight and val of items"<<endl;
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<"enter maximum wt "<<endl;
    cin>>W;
    vector<vector<int>>dp(n+1,vector<int>(W+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
            }
            
        }
    }
    cout<<"maximize value is "<<dp[n][W];
    return 0;
}