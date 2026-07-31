class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int OFFSET = 1000;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(2001, 0));

        dp[n][target + OFFSET] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int sum = -1000; sum <= 1000; sum++) {
                int ways = 0;

                if (sum + nums[i] <= 1000)
                    ways += dp[i + 1][sum + nums[i] + OFFSET];

                if (sum - nums[i] >= -1000)
                    ways += dp[i + 1][sum - nums[i] + OFFSET];

                dp[i][sum + OFFSET] = ways;
            }
        }

        return dp[0][OFFSET];
    }
};