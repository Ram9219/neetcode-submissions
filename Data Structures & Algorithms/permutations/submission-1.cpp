class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        do {
            ans.push_back(nums);
        } while (next_permutation(begin(nums), end(nums)));
        return ans;
    }
};
