class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            arr[i]=abs((int)(s[i]-t[i]));
        }
        int i=0;
        int ans=0;
        int count=0;
        for(int j=0;j<n;j++){
            count+=arr[j];
            while(count>maxCost&&i<=j){
                count-=arr[i];
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};