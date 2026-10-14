class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid;
        int ub=n; //upper bound
        while(l<=h){
            mid = l + (h-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                h=mid-1;
                ub=mid;
            }
            else l=mid+1;
        }
        return ub;
    }
};

//TC -> O(N), SC -> O(1)