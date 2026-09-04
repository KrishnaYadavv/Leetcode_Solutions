class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int i=0;
        int sum=0;
        int ans=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            mpp[nums[j]]++;
            while(mpp.size()<j-i+1){
                sum-=nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};