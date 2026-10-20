class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)return false;
        map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        while(!mpp.empty()){
            auto it=mpp.begin();
            int val=it->first;
            for(int i=0;i<k;i++){
                auto j=mpp.find(val+i);
                if(j==mpp.end())return false;
                j->second--;
                if(j->second==0){
                    mpp.erase(j);
                }
            }
        }
        return true;
    }
};