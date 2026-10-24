class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1;
        int mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target) return true;
            //case where it is undetermined mid lying after the pivot being equal to first element where values after the mid must be sorted and should be less than nums[l] forcing nums[h] to be equal to nums[mid]
            else if(nums[l]==nums[mid] && nums[h]==nums[mid]){
                l++;
                h--;
            }
            //Check if left of mid sorted
            else if(nums[mid]>=nums[l]){
                //Check if target exists within the range
                if(nums[l]<=target && target<nums[mid]) h=mid-1;
                //Then it might be there in the other half
                else l=mid+1;
            }
            //If left is not sorted then the right must be sorted
            else{
                //Check if target exists within the range
                if(nums[h]>=target && target>nums[mid]) l=mid+1;
                //Then it might be there in the other half
                else h=mid-1;
            }
        }
        return false;
    }
    //TC -> O(logn), SC -> O(1)
};