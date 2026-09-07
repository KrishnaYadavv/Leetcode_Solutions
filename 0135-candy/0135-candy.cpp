class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        vector<int>arr(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                arr[i]=max(arr[i],arr[i+1]+1);
            }
        }
        int sum=accumulate(arr.begin(),arr.end(),0);
        return sum;
    }
};