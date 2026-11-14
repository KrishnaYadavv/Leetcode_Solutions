class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            nums[i]=sum;
        }
        // int temp=INT_MAX;
        // if(l==r){
        //     if(nums[l-1]>0){
        //         temp=min(temp,nums[l-1]);
        //     }
        //     for(int i=l;i<n;i++){
        //         int curr=nums[i]-nums[i-l];
        //         if(curr<=0){
        //             continue;
        //         }
        //         temp=min(temp,curr);
        //     }
        //     return temp==INT_MAX ? -1:temp;
        // }
        int fans=INT_MAX;
        for(int i=l-1;i<n;i++){
            for(int j=i-(r-1)-1;j<i-(l-1);j++){
                if(j>=0){
                    int curr=nums[i]-nums[j];
                    if(curr<=0){
                        continue;
                    }
                    fans=min(fans,curr);
                }
                else{
                    int curr=nums[i];
                    if(curr<=0){
                        continue;
                    }
                    fans=min(fans,curr);
                }
            }
        }
        return fans==INT_MAX ? -1 : fans;
    }
};