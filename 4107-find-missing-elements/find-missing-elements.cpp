class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int l = 101,r = 0;

        unordered_set<int> st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
            l = min(l,nums[i]);
            r = max(r,nums[i]);
        }

        vector<int> ans;

        for(int i=l;i<=r;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};