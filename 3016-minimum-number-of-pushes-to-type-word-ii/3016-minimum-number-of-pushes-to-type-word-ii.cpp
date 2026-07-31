class Solution {
public:
    int minimumPushes(string word) {
        vector<int>arr(26,0);
        for(auto i:word){
            arr[i-'a']++;
        }
        sort(arr.rbegin(),arr.rend());
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=arr[i]*int((i+8)/8);
        }
        return ans;
        
    }
};