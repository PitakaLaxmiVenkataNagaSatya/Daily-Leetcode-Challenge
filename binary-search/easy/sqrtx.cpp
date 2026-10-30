class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l=1;
        int h=x/2;
        long long mid;
        int possibleRoot = 0;
        while(l<=h){
            mid=l+(h-l)/2;
            if(mid==x/mid) return mid;
            else if(mid<x/mid){
                possibleRoot=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return possibleRoot;
    }
    //TC->O(logN), SC->O(1)
};