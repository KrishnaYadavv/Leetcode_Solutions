class Solution {
public:

int findMax(vector<int>&piles){
    int temp=INT_MIN;
    for(int i=0;i<piles.size();i++){
        temp=max(temp,piles[i]);
    }
    return temp;
}


long long int hF(vector<int>&piles,int mid){
     long long int th=0;
    for(int i=0;i<piles.size();i++){
        th+=ceil(double(piles[i])/double(mid));
    }
    return th;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findMax(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long int tH=hF(piles,mid);
            if(tH<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};