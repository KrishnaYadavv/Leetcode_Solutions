class Solution {
public:

bool possible(vector<int>& nums,int mid,int k){
    int count=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid)return false;
        if(sum+nums[i]>mid){
            count++;
            sum=nums[i];
        }
        else{
            sum+=nums[i];
        }
    }
    if(count>k)return false;
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};