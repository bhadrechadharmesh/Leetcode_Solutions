class Solution {
    vector<vector<int>> dp;

    int helper(vector<int>& piles, int start, int end) {
        if(start == end)
            return piles[start];

        if(dp[start][end] != -1)
            return dp[start][end];

        int left = piles[start] - helper(piles,start+1,end);
        int right = piles[end] - helper(piles,start,end-1);

        return dp[start][end] = max(left,right);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n,-1));

        return helper(piles,0,n-1) > 0;
    }
};