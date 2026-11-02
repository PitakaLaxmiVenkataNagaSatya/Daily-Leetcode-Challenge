class Solution {
public:
    bool isValid(vector<int>& arr, int x, int threshold){
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i]/x;
            if(arr[i]%x!=0) sum ++;
        }        
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e = *max_element(nums.begin(), nums.end());
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
            if(isValid(nums, mid, threshold)) e=mid;
            else s=mid+1;
        }
        return s;
    }
};

//TC->O(N*logM) , SC->O(1)   {M is maximum element, so bs for 1 to M is logM and each has n iterations}