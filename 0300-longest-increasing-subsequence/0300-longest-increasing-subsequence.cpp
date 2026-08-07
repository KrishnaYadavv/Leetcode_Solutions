class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            int temp=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    temp=max(temp,1+dp[j]);
                }
            }
            dp[i]=temp;
        }
        int ans=0;
        for(auto i:dp){
            ans=max(ans,i);
        }
        return ans;
    }
};