class Solution {
public:

bool possible(vector<int>& weights, int mid, int days){
    int count=0;
    int temp=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]>mid){
            return false;
        }
        else if(count+weights[i]<=mid){
            count+=weights[i];
        }
        else{
            temp+=1;
            count=0;
            count=weights[i];
        }
    }
    if(count>0)temp+=1;
    if(temp<=days)return true;
    return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1;
        int high=500*weights.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(weights,mid,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};