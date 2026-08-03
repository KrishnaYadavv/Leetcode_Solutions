class Solution {
public:

int hF(int i,vector<int>&sV,vector<int>&dp){
    if(i==sV.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int a1,a2,a3;
    a1=a2=a3=INT_MIN;
    if(i<sV.size()){
        a1=sV[i]-hF(i+1,sV,dp);
    }
    if(i+1<sV.size()){
        a2=sV[i]+sV[i+1]-hF(i+2,sV,dp);
    }
    if(i+2<sV.size()){
        a3=sV[i]+sV[i+1]+sV[i+2]-hF(i+3,sV,dp);
    }
    int temp=max(a1,a2);
    temp=max(temp,a3);
    return dp[i]= temp;

}
    string stoneGameIII(vector<int>& sV) {
        int n=sV.size();
        vector<int>dp(n,-1);
        int ans=hF(0,sV,dp);
        if(ans>0)return "Alice";
        if(ans<0)return "Bob";
        return "Tie";
    }
};