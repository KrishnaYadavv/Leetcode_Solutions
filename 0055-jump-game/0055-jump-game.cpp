class Solution {
public:
    bool canJump(vector<int>& nums) {
        int count=0;
        for(auto i:nums){
            if(i==0)count++;
        }
        if(nums.size()==1)return true;
        if(count==0)return true;
        if(nums[0]==0)return false;
        int n=nums.size()-1;
        int j=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0&&j==-1){
                j=i;
            }
            else if(j>=0){
                if(i+nums[i]>j){
                    j=-1;
                }
            }
        }
        return j==-1;
        
    }
};