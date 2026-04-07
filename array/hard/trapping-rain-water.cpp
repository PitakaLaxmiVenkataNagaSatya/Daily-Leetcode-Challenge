class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0; 
        int r=n-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(l<r){
            lmax=max(lmax, height[l]);
            rmax=max(rmax, height[r]);
            if(lmax<rmax){
                ans += lmax-height[l];
                l++;
            }
            else{
                ans += rmax-height[r];
                r--;
            }
            //it even works without this condition but I'have just added my observation but if l and r may point at same and loop breaks and gives incomplete result
            // else{
            //     ans += lmax-height[l];
            //     ans += rmax-height[r];
            //     l++;
            //     r--;
            // }
        }
        return ans; //TC -> O(N) SC -> O(1)
    }
};