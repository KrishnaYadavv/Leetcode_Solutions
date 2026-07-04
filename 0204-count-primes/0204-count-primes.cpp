class Solution {
public:
    int countPrimes(int n) {
        if(n<2)return 0;
        vector<int>nums(n,1);
        for(int i=2;i*i<=n;i++){
            for(int j=i+i;j<n;j=j+i){
                nums[j]=0;
            }
        }
        int count=0;
        nums[0]=0;
        nums[1]=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)count++;
        }
        return count;
    }
};