class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int temp=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(auto i:nums){
            ans+=abs(i-temp);
        }
        return ans;
    }
};