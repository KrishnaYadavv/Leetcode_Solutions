class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int n=nums.size()-1;
        ans=nums[n]*nums[n-1]*nums[n-2];
        int temp=1;
        temp=nums[0]*nums[1]*nums[n];
        ans=max(ans,temp);
        return ans;
        
    }
};