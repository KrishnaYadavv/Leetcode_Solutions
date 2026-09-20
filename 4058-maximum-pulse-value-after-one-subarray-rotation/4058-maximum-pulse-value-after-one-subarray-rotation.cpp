class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i%2==1){
                nums[i]=-1*nums[i];
            }
        }
        long long ans=accumulate(nums.begin(),nums.end(),0LL);
        int i=0;
        int j=1;
        long long mn[2]={0,LLONG_MIN};
        long long prefix=0;
        long long minpref=0;
        for(int i=1;i<=n;i++){
            prefix+=nums[i-1];
            int p=i%2;
            if(mn[p]!=LLONG_MIN){
                minpref=min(minpref,prefix-mn[p]);
            }
            mn[p]=max(mn[p],prefix);
        }
        return ans-2*minpref;
        
    }
};