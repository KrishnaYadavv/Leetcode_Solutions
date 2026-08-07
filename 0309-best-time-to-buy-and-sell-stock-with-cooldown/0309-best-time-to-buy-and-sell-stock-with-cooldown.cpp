class Solution {
public:
int hF(int i,int j,vector<int>&prices,vector<vector<int>>&dp){
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(j%2==0){
        ans=max(-prices[i]+hF(i+1,1,prices,dp),hF(i+1,j,prices,dp));
    }
    else{
        ans=max(prices[i]+hF(i+2,0,prices,dp),hF(i+1,j,prices,dp));
    }
    return dp[i][j]=ans;
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return hF(0,0,prices,dp);
        
    }
};