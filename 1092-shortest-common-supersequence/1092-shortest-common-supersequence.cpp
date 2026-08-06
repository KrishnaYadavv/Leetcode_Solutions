class Solution {
public:
    int hF(string& s1, string& s2, vector<vector<int>>& dp) {
        int n = s1.size();
        int m = s2.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }

    string hP(string& s1, string& s2,vector<vector<int>>&dp,int n,int m,string ans){
        if(n==0||m==0){
            return ans;
        }
        if(s1[n-1]==s2[m-1]){
            return hP(s1,s2,dp,n-1,m-1,ans+s1[n-1]);
        }
        else{
            if(dp[n][m-1]>dp[n-1][m]){
                return hP(s1,s2,dp,n,m-1,ans);
            }
            else{
                return hP(s1,s2,dp,n-1,m,ans);
            }
        }
    }

        string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        hF(s1, s2, dp);
        string ans = hP(s1,s2,dp,n,m,"");
        reverse(ans.begin(),ans.end());
        int i,j,k;
        i=j=k=0;
        string fans;
        while(i<s1.size()&&j<ans.size()&&k<s2.size()){
            if(s1[i]==ans[j]&&ans[j]==s2[k]){
                fans+=s1[i];
                i++;
                j++;
                k++;
            }
            else if(s1[i]==ans[j]&&ans[j]!=s2[k]){
                fans+=s2[k];
                k++;
            }
            else if(s1[i]!=ans[j]&&ans[j]==s2[k]){
                fans+=s1[i];
                i++;
            }
            else{
                fans+=s1[i];
                fans+=s2[k];
                i++;
                k++;
            }
        }
        if(i<s1.size()){
            fans+=s1.substr(i);
        }
        if(k<s2.size()){
            fans+=s2.substr(k);
        }
        return fans;
    }
};