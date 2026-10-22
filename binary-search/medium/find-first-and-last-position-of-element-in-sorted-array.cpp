class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, h=n-1;
        int Fp=-1; //first position
        int Lp=-1; //last position
        int mid;
        //For finding the first position
        while(l<=h){
            mid = l + (h-l)/2;
            if(nums[mid]==target){
                Fp=mid;
                h=mid-1;
            }
            else if(nums[mid]<target) l = mid + 1;
            else h = mid - 1;
        }
        l=0;
        h=n-1;
        mid=0;
        //For finding the last position
        while(l<=h){
            mid = l + (h-l)/2;
            if(nums[mid]==target){
                Lp=mid;
                l=mid+1;
            }
            else if(nums[mid]<target) l = mid + 1;
            else h=mid-1;
        }
        return {Fp, Lp};
    }
};