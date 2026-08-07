class Solution {
public:

int hF(int i,vector<int>&prices,int t,int k,vector<vector<int>>&dp){
    if(t==k){
        return 0;
    }
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][t]!=-1){
        return dp[i][t];
    }
    int ans=0;
    if(t%2==0){
        ans=max(-prices[i]+hF(i+1,prices,t+1,k,dp),hF(i+1,prices,t,k,dp));
    }
    else{
        ans=max(prices[i]+hF(i+1,prices,t+1,k,dp),hF(i+1,prices,t,k,dp));
    }
    return dp[i][t]= ans;
}
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k,-1));
        return hF(0,prices,0,2*k,dp);
    }
};