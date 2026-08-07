class Solution {
public:

bool hF(int i,int j,string& s, string& p,vector<vector<int>>&dp){
    if(i==-1&&j==-1){
        return true;
    }
    if(j==-1){
        return false;
    }
    if(i==-1){
        while(j>=0){
            if(p[j]=='*'){
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    if(s[i]!=p[j]&&p[j]!='?'&&p[j]!='*'){
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    bool a,b,c,d;
    a=b=c=d=false;
    if(s[i]==p[j]){
        return dp[i][j]=hF(i-1,j-1,s,p,dp);
    }
    if(p[j]=='?'){
        a=hF(i-1,j-1,s,p,dp);
    }
    if(p[j]=='*'){
        b=hF(i-1,j,s,p,dp);
        c=hF(i-1,j-1,s,p,dp);
        d=hF(i,j-1,s,p,dp);
    }
    return dp[i][j]=a||b||c||d;
}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return hF(n-1,m-1,s,p,dp);
    }
};