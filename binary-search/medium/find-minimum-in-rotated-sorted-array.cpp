class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1;
        int mid;
        int minVal=INT_MAX;
        while(l<=h){
            mid=l+(h-l)/2;
            minVal=min(nums[mid], minVal);
            if(nums[mid]<nums[l]) h=mid-1;
            else{
                if(nums[mid]<nums[h]) h=mid-1;
                else l=mid+1;
            }
        }
        return minVal;
    }
};

//TC -> O(logN), SC -> O(1)