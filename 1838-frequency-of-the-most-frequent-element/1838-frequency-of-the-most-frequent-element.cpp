class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        vector<int>arr(n,0);
        for(int j=1;j<n;j++){
            arr[j]=nums[j]-nums[j-1];
        }
        int i=0;
        long long count=0;
        for(int j=1;j<n;j++){
            count+=(long long)arr[j]*(j-i);
            while(count>k&&i<j){
                count-=(long long)nums[j]-nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};