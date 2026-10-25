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
            //if mid is right side of pivot
            if(nums[mid]<nums[l]) h=mid-1;
            //if mid is left side of pivot
            else{
                //if array is not rotated n times
                if(nums[mid]<nums[h]) h=mid-1;
                else l=mid+1; //if array is rotated n times
            }
        }
        return minVal;
    }
};

//TC -> O(logN), SC -> O(1)