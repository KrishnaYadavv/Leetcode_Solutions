class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                temp.push_back(i);
            }
        }
        int ans=0;
        for(auto k:temp){
            int j=0;
            bool flag=true;
            int v1=INT_MIN;
            while(j<n){
                int count=0;
                bool flag1=true;
                bool flag2=false;
                int temp=INT_MIN;
                int mi=nums[j];
                int ma=nums[j];
                for(int i=1;i<k;i++){
                    if(nums[j+i]<nums[j+i-1]){
                        temp=mi;
                        flag2=true;
                        count++;
                    }
                    if(flag2&&nums[j+i]>temp){
                        flag1=false;
                        break;
                    }
                    mi=min(mi,nums[j+i]);
                    ma=max(ma,nums[j+i]);    
                }
                if(v1<=mi&&count<2&&flag1){
                    j+=k;
                    v1=max(v1,ma);
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans+=k;
            }
        }
        return ans;
    }
};