class Solution {
    bool helper(vector<int>& nums,int start,int end,int score1,int score2,int turn){
        if(start>end){
            return score1>=score2;
        }

        bool ans = true;

        if(turn == 1){
            if(helper(nums,start+1,end,score1+nums[start],score2,2)){
                return true;
            }
            ans = helper(nums,start,end-1,score1+nums[end],score2,2);
        }else{
            return helper(nums,start,end-1,score1,score2+nums[end],1) && helper(nums,start+1,end,score1,score2+nums[start],1);
        }

        return ans;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return helper(nums,0,n-1,0,0,1);
    }
};