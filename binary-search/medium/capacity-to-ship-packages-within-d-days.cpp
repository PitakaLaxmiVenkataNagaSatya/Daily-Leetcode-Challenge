class Solution {
public:

    bool isPossible(vector<int>& weights, int days, int capacity){
        int daysTaken=1;
        int weightSeen=0;
        for(int i=0; i<weights.size(); i++){
            if(weightSeen + weights[i]>capacity){
                daysTaken++;
                weightSeen = weights[i];
            }
            else weightSeen += weights[i];
        }
        return daysTaken<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end());
        int h=accumulate(weights.begin(), weights.end(), 0);
        int ans=h;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isPossible(weights, days, mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};

//TC -> O(N*LogS) {S = h-l+1}  , SC -> O(1)