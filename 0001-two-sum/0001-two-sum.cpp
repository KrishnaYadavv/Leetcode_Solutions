class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                if((nums[i]+nums[j])==target){
                    a=i;
                    b=j;
                }
            }

        }
        vector<int>vec={a,b};

        return vec;
    }
};