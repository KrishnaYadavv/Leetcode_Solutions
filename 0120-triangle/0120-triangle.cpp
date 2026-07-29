class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=INT_MAX;
        int n=triangle.size();
        if(n==1)return triangle[0][0];
        vector<vector<int>>dp;
        dp.push_back(triangle[0]);
        for(int i=1;i<n;i++){
            vector<int>temp(triangle[i].size(),0);
            dp.push_back(temp);
            for(int j=0;j<temp.size();j++){
                int val=INT_MAX;
                if(j-1>=0){
                    val=min(val,dp[i-1][j-1]);
                }
                if(j!=temp.size()-1){
                    val=min(val,dp[i-1][j]);
                }
                dp[i][j]=triangle[i][j]+val;
                if(i==n-1){
                    ans=min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};