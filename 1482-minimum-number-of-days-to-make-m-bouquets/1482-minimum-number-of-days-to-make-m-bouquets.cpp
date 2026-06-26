class Solution {
public:

int  findMin(vector<int>& bloomDay){
    int temp=INT_MAX;
    for(int i=0;i<bloomDay.size();i++){
        temp=min(temp,bloomDay[i]);
    }
    return temp;
}

int  findMax(vector<int>& bloomDay){
    int temp=INT_MIN;
    for(int i=0;i<bloomDay.size();i++){
        temp=max(temp,bloomDay[i]);
    }
    return temp;
}

bool possible(vector<int>& bloomDay, int day, int m, int k){
    int count=0;
    int temp=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            count++;
        }
        else{
            temp+=count/k;
            count=0;
        }
    }
    temp+=count/k;
    if(temp>=m)return true;
    return false;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=findMin(bloomDay);
        int high=findMax(bloomDay);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};