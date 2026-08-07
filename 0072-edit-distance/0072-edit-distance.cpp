class Solution {
public:
    int hF(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        {
            if (i < 0) {
                return j+1;
            }
            if(j<0){
                return i+1;
            }
            if (dp[i][j]!= -1) {
                return dp[i][j];
            }

            int ans = 0;
            int a, b, c;
            if (s1[i] == s2[j]) {
                return dp[i][j]=hF(i-1,j-1,s1,s2,dp);
            }
            if (j >= 0) {
                a = 1 + hF(i, j - 1, s1, s2, dp);
            }
            if (i >= 0) {
                b = 1 + hF(i - 1, j, s1, s2, dp);
            }
            if (i >= 0 && j >= 0) {
                c = 1 + hF(i - 1, j - 1, s1, s2, dp);
            }
            int temp;
            temp=min(a,b);
            temp=min(temp,c);
            return dp[i][j]=temp;
        }
    }

    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return hF(n - 1, m - 1, s1, s2, dp);
    }
};