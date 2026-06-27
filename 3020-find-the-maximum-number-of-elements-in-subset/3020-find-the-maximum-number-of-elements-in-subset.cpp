class Solution {
public:

    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans=1;
        if (mpp.count(1)) {
            int c = mpp[1];
            if (c % 2 == 0) c--; 
            ans = max(ans, c);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)continue;
            else if(mpp[nums[i]]>=2){
                int count=1;
                long long int n=(long long)nums[i]*nums[i];
                while(1){
                    if(mpp.find(n)!=mpp.end()){
                        count+=2;
                        ans=max(ans,count);
                        if(mpp[n]>=2){
                            if(n>1e9)break;
                            n=n*n;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        ans=max(ans,count);
                        break;
                    }
                }
            }
            else{

            }
        }
        return ans;
    }
};