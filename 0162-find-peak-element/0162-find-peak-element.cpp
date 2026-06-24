class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])return nums.size()-1;
        int low=0;
        int high=nums.size()-1;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(low==high)return low;
            else if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid;
            else if(nums[mid]<nums[high])low=mid+1;
            else if(nums[mid]<nums[low])high=mid-1;
            else if(nums[mid]>=nums[low]||nums[mid]>=nums[high]){
                low++;
                high--;
            }
            else{

            }
        }
        return -1;
    }
};