class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1;
        int mid;
        if(n==1) return nums[0];
        while(l<=h){
            mid=l+(h-l)/2;
            if(mid==0 && nums[0]!=nums[1]) return nums[mid];
            if(mid==n-1 && nums[n-1]!=nums[n-2]) return nums[mid];
            
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            
            if(mid%2==0){ //even
                if(nums[mid]==nums[mid-1]) h=mid-1;//left
                else l=mid+1;//right
            }
            else{//odd
                if(nums[mid]==nums[mid-1]) l=mid+1;//right
                else h=mid-1;//left
            }
        }
        return -1;
    }
    //TC->O(logN) , SC->O(1)
};