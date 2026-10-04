class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& list, int idx, int n){
        if(idx == n){
            ans.push_back(list);
            return;
        }
        list.push_back(nums[idx]);
        backtrack(nums, ans, list, idx+1, n);
        list.pop_back();
        backtrack(nums, ans, list, idx+1, n);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        int n=nums.size();
        backtrack(nums, ans, list, 0, n);
        return ans;
    }
};