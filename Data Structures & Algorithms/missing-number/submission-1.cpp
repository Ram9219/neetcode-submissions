class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int ans = 0;
        while (st.count(ans)){
            ans++;
        }
        return ans;
    }
};
