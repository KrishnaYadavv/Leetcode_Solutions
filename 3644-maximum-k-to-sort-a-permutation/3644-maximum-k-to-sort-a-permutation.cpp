class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        int n=nums.size();
        int k=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                k=k&i;
            }
        }
        return k;
    }
};