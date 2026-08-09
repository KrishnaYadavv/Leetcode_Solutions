class Solution {
public:
    int hF(int i, int m, vector<int>& piles,
           vector<int>& suffix, vector<vector<int>>& dp) {

        int n = piles.size();

        if (i >= n)
            return 0;

        if (dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;

        for (int x = 1; x <= 2 * m && i + x <= n; x++) {

            // Stones opponent can get
            int opponent = hF(i + x, max(m, x), piles, suffix, dp);

            // Total stones from i onward
            int total = suffix[i];

            // Current player gets total - opponent
            int current = total - opponent;

            ans = max(ans, current);
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return hF(0, 1, piles, suffix, dp);
    }
};