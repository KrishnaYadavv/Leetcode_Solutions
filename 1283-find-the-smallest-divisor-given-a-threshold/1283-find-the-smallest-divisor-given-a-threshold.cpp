class Solution {
public:

int  findMax(vector<int>& nums){
    int temp=INT_MIN;
    for(int i=0;i<nums.size();i++){
        temp=max(temp,nums[i]);
    }
    return temp;
}

bool possible(vector<int>& nums, int mid, int threshold){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil((double)nums[i]/mid);
    }
    if(sum>threshold)return false;
    return true;
}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=findMax(nums);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,mid,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};