class Solution {
public:
    int canCompleteCircuit(vector<int>& nums, vector<int>& arr) {
        int n=nums.size();
        int sum1=accumulate(nums.begin(),nums.end(),0);
        int sum2=accumulate(arr.begin(),arr.end(),0);
        if(sum1<sum2)return -1;
        int idx=0;
        int flag=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]-arr[i];
            if(sum<0){
                flag=1;
                sum=0;
            }
            if(nums[i]>arr[i]&&flag==1){
                idx=i;
                flag=0;
            }
        }
        return idx;
    }
};