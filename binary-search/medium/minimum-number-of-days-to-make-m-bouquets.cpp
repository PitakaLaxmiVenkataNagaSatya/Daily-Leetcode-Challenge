class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day){
        int consecutive=0;
        int bouquet=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                consecutive++;
                if(consecutive==k){
                    bouquet++;
                    consecutive=0;
                }
            }
            else{
                consecutive=0;
            }
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(), bloomDay.end());
        int h=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(bloomDay, m, k, mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
//TC -> O(N*logRange) Range = h-l+1 , SC -> O(1)