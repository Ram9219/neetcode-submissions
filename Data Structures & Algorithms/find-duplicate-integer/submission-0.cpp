class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>freq(nums.size());
        for(auto &it:nums){
            freq[it]++;
            if(freq[it]>1){
                return it;
            }
        }
        return -1;
    }
};
