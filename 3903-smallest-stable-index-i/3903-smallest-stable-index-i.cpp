class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n);
        int temp=INT_MAX;
        for(int i=n-1;i>=0;i--){
            temp=min(temp,nums[i]);
            arr[i]=temp;
        }
        temp=-1;
        for(int i=0;i<n;i++){
            temp=max(temp,nums[i]);
            if(temp-arr[i]<=k){
                return i;
            }
        }
        return -1;   
    }
};