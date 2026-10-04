class Solution {
public:
    void swap(int & a, int & b){
        int temp = b; 
        b = a;
        a = temp;
        return;
    }
    // void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& list, int idx, int n){
    //     if(idx==n){
    //         ans.push_back(list);
    //         return;
    //     }
    //     for(int i=idx; i<n; i++){
    //         swap(nums[i], nums[idx]);
    //         list.push_back(nums[idx]);
    //         backtrack(nums, ans, list, idx+1, n);
    //         list.pop_back();
    //         swap(nums[i], nums[idx]);
    //     }
    //     return;
    // }

    //Most optimised without using any extra vector
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, int n){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            swap(nums[i], nums[idx]);
            backtrack(nums, ans, idx+1, n);
            swap(nums[i], nums[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> list;
        int n=nums.size();
        // backtrack(nums, ans, list, 0, n);
        backtrack(nums, ans, 0, n);
        return ans;
    }
};