class Solution {
public:
    int ceilSum(vector<int>& arr, int x){
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]%x!=0) sum += arr[i]/x + 1;
            else sum += arr[i]/x;
        }        
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e = *max_element(nums.begin(), nums.end());
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
            int sum=ceilSum(nums, mid);
            if(sum<=threshold) e=mid;
            else s=mid+1;
        }
        return s;
    }
};