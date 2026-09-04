class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.size();
        if(n<=2)return n;
        int i=1;
        int count=0;
        int ans=0;
        for(int j=1;j<n;j++){
            if(s[j]==s[j-1]){
                count++;
            }
            while(count>1){
                if(s[i]==s[i-1]){
                    count--;
                }
                i++;
            }
            ans=max(ans,j-i+2);
        }
        return ans;
    }
};