class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int sum1=0;
        for(int i=0;i<n;i++){
            sum1+=abs(nums[i]-low);
        }
        return sum1;
        
    }
};