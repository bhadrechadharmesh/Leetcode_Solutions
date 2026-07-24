class Solution {

    int helper(vector<int>& nums,int target,int n,int currSum,vector<vector<int>> &dp,int sum){
        if(n==nums.size() && currSum == target){
            return 1;
        }else if(n==nums.size())return 0;

        if(dp[n][currSum+sum]!=-1)return dp[n][currSum+sum];

        int ans = helper(nums,target,n+1,currSum+nums[n],dp,sum) + helper(nums,target,n+1,currSum-nums[n],dp,sum);

        return dp[n][currSum+sum]=ans;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num:nums)sum+=num;

        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,-1));

        
        return helper(nums,target,0,0,dp,sum);
    }
};