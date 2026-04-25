class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        //find the pivot   
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        //check and reverse the array if it is the final permutation
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //find the appropriate element to swap with pivot
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
                }
            }
        //sort elements after the pivot
        reverse(nums.begin()+index+1, nums.end());
        return;
    }
};