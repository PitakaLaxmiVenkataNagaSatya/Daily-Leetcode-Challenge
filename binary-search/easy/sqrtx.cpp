class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int h=x/2;
        long long mid;
        int possibleRoot = 0;
        if(x==1) return 1;
        while(l<=h){
            mid=l+(h-l)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid<x){
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