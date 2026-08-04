class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i:nums){
            mpp[i]++;
            low=min(low,i);
            high=max(high,i);
        }
        vector<int>ans;
        for(int i=low;i<=high;i++){
            if(mpp.find(i)==mpp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};