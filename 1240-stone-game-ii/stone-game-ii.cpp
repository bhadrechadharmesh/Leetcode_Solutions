class Solution {
    vector<vector<int>> dp;

    int helper(vector<int>& piles, int idx, int M) {
        int n = piles.size();

        if (idx == n)
            return 0;

        if (dp[idx][M] != -1)
            return dp[idx][M];

        int ans = INT_MIN;
        int sum = 0;

        for (int X = 1; X <= 2 * M && idx + X <= n; X++) {
            sum += piles[idx + X - 1];

            int opponent = helper(
                piles,
                idx + X,
                max(M, X)
            );

            ans = max(ans, sum - opponent);
        }

        return dp[idx][M] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        dp.assign(n, vector<int>(n + 1, -1));

        int diff = helper(piles, 0, 1);

        // Alice + Bob = total stones
        // Alice - Bob = diff
        //
        // Therefore:
        // Alice = (total + diff) / 2

        int total = accumulate(piles.begin(), piles.end(), 0);

        return (total + diff) / 2;
    }
};