class Solution {
    int helper(vector<int>& nums, int idx, vector<int>& dp) {
        int n = nums.size();

        if (idx >= n) return 0;

        if (dp[idx] != -1e9)
            return dp[idx];

        int sum = 0;
        int ans = -1e9;

        for (int i = 0; i < 3 && idx + i < n; i++) {
            sum += nums[idx + i];
            ans = max(ans, sum - helper(nums, idx + i + 1, dp));
        }

        return dp[idx] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, -1e9);

        int diff = helper(stoneValue, 0, dp);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};