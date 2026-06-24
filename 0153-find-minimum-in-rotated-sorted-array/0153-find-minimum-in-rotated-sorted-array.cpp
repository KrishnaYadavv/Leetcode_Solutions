class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(low==high)return ans;
            if(nums[mid]>=nums[low]){
                low=mid+1;
                ans=min(ans,nums[low]);
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};