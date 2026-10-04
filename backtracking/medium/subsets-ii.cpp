class Solution {
public:

    vector<vector<int>> allSubsets;
    vector<int> list;
    void backtrack(vector<int>& nums, int idx, int n){
        if(idx==n){
            allSubsets.push_back(list);
            return;
        }
        list.push_back(nums[idx]);
        backtrack(nums, idx+1, n);
        list.pop_back();
        idx++;
        while(idx<n && nums[idx]==nums[idx - 1]) idx++;
        backtrack(nums, idx, n);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        backtrack(nums, 0, n);
        return allSubsets;
    }
};