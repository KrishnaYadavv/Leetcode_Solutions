class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            dp[i][amount]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int sum=amount-1;sum>=0;sum--){
                long long int temp=0;
                if(sum+coins[i]<=amount){
                    temp+=dp[i][sum+coins[i]];
                }
                if(i+1<n){
                    temp+=dp[i+1][sum];
                }
                dp[i][sum]=temp;
            }
        }
        return dp[0][0]; 
    }
};