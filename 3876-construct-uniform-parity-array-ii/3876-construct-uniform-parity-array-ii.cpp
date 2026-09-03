class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int val=INT_MAX;
        for(auto &i:nums)val=min(val,i);
        if(val%2==0)for(auto &i:nums)if(i%2==1)return false;
        return true;
    }
};