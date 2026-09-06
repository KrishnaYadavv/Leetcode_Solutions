class Solution {
public:
// int hF(string& s,string& t,int n,int m,vector<vector<int>>&dp){
//     if(m==-1){
//         return 1;
//     }
//     if(n<0){
//         return 0;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }
//     int ans=0;
//     if(s[n]==t[m]){
//         ans+=hF(s,t,n-1,m-1,dp);
//     }
//     ans+=hF(s,t,n-1,m,dp);
//     return dp[n][m]= ans;
// }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                long long int ans=0;
                if(s[i-1]==t[j-1]){
                    ans+=dp[i-1][j-1];
                }
                ans+=dp[i-1][j];
                dp[i][j]=ans;
            }
        }
        return dp[n][m];
    }
};