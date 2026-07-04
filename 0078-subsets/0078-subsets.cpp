class Solution {
public:

void hF(int i,vector<int>& nums,vector<int>temp,vector<vector<int>>&ans,int check){
    if(check==0){
        ans.push_back(temp);
    }
    if(i==nums.size())return;
    temp.push_back(nums[i]);
    hF(i+1,nums,temp,ans,0);
    temp.pop_back();
    hF(i+1,nums,temp,ans,1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        hF(0,nums,temp,ans,0);
        return ans;
    }
};