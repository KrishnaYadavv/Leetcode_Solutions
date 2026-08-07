class Solution {
public:
    int hF(int i, vector<int>& nums, int j, vector<vector<int>>& dp) {
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int a, b;
        a = b = 0;
        if (j == nums.size()) {
            a = 1 + hF(i - 1, nums, i, dp);
        } else if (nums[i] < nums[j]) {
            a = 1 + hF(i - 1, nums, i, dp);
        }
        b = hF(i - 1, nums, j, dp);
        return dp[i][j] = max(a, b);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return hF(n - 1, nums, n, dp);
    }
};