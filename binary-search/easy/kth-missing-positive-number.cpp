class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int h=arr.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]-(mid+1)<k) l=mid+1;
            else h=mid-1;
        }
        return l+k; 

        /*
        arr[h] + more
        arr[h] + (k - (arr[h] -(h-1))
        arr[h] + k - arr[h] + h + 1
        h + 1 + k    {wherer h + 1 is simply l}
        l + k
        */
    }
};

//TC -> O(logN) , SC -> O(1)