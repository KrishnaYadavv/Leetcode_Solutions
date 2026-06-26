class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]-mid-1<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low+k;
        // int ans=0;
        // if(low==arr.size()){
        //     ans=arr[arr.size()-1]+abs(mid+1+k-arr[arr.size()-1]);
        //     return ans;
        // }
        // ans=arr[mid]+abs(arr[mid]-mid-1-k-1);
        // return ans;
    }
};