class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==1)return 1;
        unordered_map<int,int>mpp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            else{
                mpp[s[j]]++;
                j++;
                ans=max(ans,j-i);
            }
        }
        return ans;
        
    }
};