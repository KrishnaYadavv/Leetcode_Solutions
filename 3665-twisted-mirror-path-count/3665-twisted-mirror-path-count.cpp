class Solution {
public:
long long mod=1e9+7;

long long hF(int i,int j,int dir,vector<vector<int>>&nums,vector<vector<vector<int>>>&dp){
    int m=nums.size();
    int n=nums[0].size();
    if(i>=m||j>=n){
        return 0;
    }
    if(i==m-1&&j==n-1){
        return 1;
    }
    if(dp[i][j][dir]!=-1){
        return dp[i][j][dir];
    }
    long long ans=0;
    if(nums[i][j]==1){
        if(dir==1){
            ans= hF(i+1,j,0,nums,dp);
        }
        else{
            ans=hF(i,j+1,1,nums,dp);
        }
    }
    else{
        ans+=hF(i,j+1,1,nums,dp);
        ans+=hF(i+1,j,0,nums,dp);
    }
    return dp[i][j][dir]=ans%mod;
}
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
        return hF(0,0,1,grid,dp);   
    }
};