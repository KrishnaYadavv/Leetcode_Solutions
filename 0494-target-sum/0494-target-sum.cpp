class Solution {
public:

const int offset=1000;

int hF(int i,int sum,int target,vector<int>nums,vector<vector<int>>&dp){
    if(i>=nums.size()){
        if(sum==target){
            return 1;
        }
        return 0;
    }
    if(dp[i][offset+sum]!=-1){
        return dp[i][offset+sum];
    }
    int a=hF(i+1,sum+nums[i],target,nums,dp);
    int b=hF(i+1,sum-nums[i],target,nums,dp);
    return dp[i][offset+sum]=a+b;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return hF(0,0,target,nums,dp);
        
    }
};