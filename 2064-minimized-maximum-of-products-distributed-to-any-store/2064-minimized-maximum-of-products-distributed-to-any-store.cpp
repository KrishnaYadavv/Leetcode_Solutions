class Solution {
public:
    int minimizedMaximum(int n, vector<int>& nums) {
        int i=1;
        int j=*max_element(nums.begin(),nums.end());
        while(i<j){
            int mid=i+(j-i)/2;
            int stores=0;
            for(auto x:nums){
                stores+=(x+mid-1)/mid;
            }
            if(stores<=n){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};