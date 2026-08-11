class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int preSum = nums[0];
        bool isValid = true;

        unordered_set<int> st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            st.insert(nums[i]);
            if(nums[i]!=nums[i-1]+1)isValid = false;
            if(isValid){
                preSum+=nums[i];
            }
        }

        for(int i=preSum ;i<=51;i++){
            if(st.find(i)==st.end())return i;
        }

        return preSum;
    }
};