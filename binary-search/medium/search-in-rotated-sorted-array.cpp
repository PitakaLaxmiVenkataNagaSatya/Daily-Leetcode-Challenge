class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1;
        int mid;
        while(l<=h){
            mid = l + (h-l)/2;
            if(nums[mid]==target) return mid;
            //is left sorted
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<nums[mid]) h=mid-1; //does target exists in this sorted left
                else l=mid+1; //search in the right unsorted half
            }
            //Then right is sorted
            else{
                if(nums[h]>=target && target>nums[mid]) l=mid+1;//does target exists in this sorted right
                else h=mid-1;//search in the left unsorted half
            }
        }
        return -1;
    }
    //TC -> O(logN), SC -> O(1)
};